**HDK template for Visual Studio 2019(vc142)**

*새로운 버젼(19.0)에 맞게 비주얼스튜디오의 환경셋업을 바꾸었습니다. 템플릿으로 만들어진 SOP_CAMDIR툴은 카메라 방향으로 노말을 만들어주는 SOP툴입니다.*

```
필요한 컴파일러: 비주얼스튜디오 2019(vc142)
```

**환경변수설정 예제:**
```
원래 이런식으로 환경변수 윈도우즈에 환경설정을 해서 VStudio에서 설정을해야하는데 일부는 반영이 되어있지 않습니다.
CUSTOM_DSO_PATH = {$HOME}\houdini19.0\dso
HOUDINI_DSO_PATH = %CUSTOM_DSO_PATH%;&
H19.0_PATH = C:\Program Files\Side Effects Software\Houdini %H19.0_VERSION% 
H19.0_VERSION = 19.0.657
```

**시스템변수설정**
```
MSVCDir C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133
```
**Path에 추가**
```
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\bin
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE
```
