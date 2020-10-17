#pragma once
#ifndef __SOP_CAMdir_h__
#define __SOP_CAMdir_h__

#include <SOP/SOP_Node.h>

namespace HDK_Sample {

	class SOP_CAMdir : public SOP_Node
	{
	public:
		SOP_CAMdir(OP_Network *net, const char *name, OP_Operator *op);
		virtual ~SOP_CAMdir();

		static PRM_Template myTemplateList[];
		static OP_Node *myConstructor(OP_Network*, const char *, OP_Operator *);

		static CH_LocalVariable	 myVariables[];

	protected:
		virtual OP_ERROR cookMySop(OP_Context &context);
		virtual bool		 evalVariableValue(
			UT_String &v,
			int i,
			int thread)
		{
			return evalVariableValue(v, i, thread);
		}

	private:
		fpreal	CENTERX(fpreal t) { return evalFloat("t", 0, t); }
		fpreal	CENTERY(fpreal t) { return evalFloat("t", 1, t); }
		fpreal	CENTERZ(fpreal t) { return evalFloat("t", 2, t); }
	};
}

#endif