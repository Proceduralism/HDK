#include "SOP_CAMdir.h"

#include <GU/GU_Detail.h>
#include <GA/GA_Handle.h>
#include <OP/OP_AutoLockInputs.h>
#include <OP/OP_Director.h>
#include <OP/OP_Operator.h>
#include <OP/OP_OperatorTable.h>
#include <PRM/PRM_Include.h>
#include <UT/UT_DSOVersion.h>
#include <SYS/SYS_Math.h>

using namespace HDK_Sample;

void
newSopOperator(OP_OperatorTable *table)
{
	table->addOperator(new OP_Operator(
		"cpp_camdir",
		"CPP CAMdir",
		SOP_CAMdir::myConstructor,
		SOP_CAMdir::myTemplateList,
		1,
		1,
		0));
}

PRM_Template
SOP_CAMdir::myTemplateList[] = {
	PRM_Template(PRM_XYZ,       3, &PRMcenterName),
	PRM_Template()
};



OP_Node *
SOP_CAMdir::myConstructor(OP_Network *net, const char *name, OP_Operator *op)
{
	return new SOP_CAMdir(net, name, op);
}

SOP_CAMdir::SOP_CAMdir(OP_Network *net, const char *name, OP_Operator *op)
	: SOP_Node(net, name, op)
{
	mySopFlags.setManagesDataIDs(true);
}

SOP_CAMdir::~SOP_CAMdir()
{
}

OP_ERROR
SOP_CAMdir::cookMySop(OP_Context &context)
{
	fpreal now = context.getTime();

	OP_AutoLockInputs inputs(this);
	if (inputs.lock(context) >= UT_ERROR_ABORT)
		return error();


	duplicateSource(0, context);


	//flags().timeDep = 1;

	fpreal frame = OPgetDirector()->getChannelManager()->getSample(context.getTime());
	frame *= 0.03;

	float tx = CENTERX(now);
	float ty = CENTERY(now);
	float tz = CENTERZ(now);

	GA_RWHandleV3 N_h(gdp, GA_ATTRIB_POINT, "N");
	GA_RWHandleV3 Phandle(gdp->findAttribute(GA_ATTRIB_POINT, "P"));
	GA_Offset ptoff;

	if (N_h.isValid())
	{
		UT_Vector3 N;
		UT_Vector3 Campos(tx, ty, tz);
		UT_Vector3 Pvalue = Phandle.get(ptoff);
		for (GA_Iterator it(gdp->getPointRange()); !it.atEnd(); ++it)
		{
			GA_Offset offset = *it;
			//UT_Vector3 N = N_h.get(offset);
			UT_Vector3 N = Campos - Pvalue;
			N.normalize();
			N_h.set(offset, N);
		}
	}

	Phandle.bumpDataId();
	return error();
}