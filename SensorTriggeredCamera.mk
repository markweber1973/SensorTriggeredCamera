##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SensorTriggeredCamera
ConfigurationName      :=Debug
WorkspacePath          := "/home/mark/DezyneWorkspace/SensorTriggeredCamera"
ProjectPath            := "/home/mark/DezyneWorkspace/SensorTriggeredCamera"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Mark
Date                   :=06/01/16
CodeLitePath           :="/home/mark/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="SensorTriggeredCamera.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -lpthread  -lwiringPi
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/home/mark/DezyneWorkspace/SensorTriggeredCamera/generated/. $(IncludeSwitch)/home/mark/DezyneWorkspace/SensorTriggeredCamera/runtime/. 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall  -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/pump.cc$(ObjectSuffix) $(IntermediateDirectory)/runtime.cc$(ObjectSuffix) $(IntermediateDirectory)/PIRSensor.cc$(ObjectSuffix) $(IntermediateDirectory)/MotionTriggeredCam.cc$(ObjectSuffix) $(IntermediateDirectory)/Camera.cc$(ObjectSuffix) $(IntermediateDirectory)/MotionTriggeredCameraSystem.cc$(ObjectSuffix) $(IntermediateDirectory)/timer.cc$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/pump.cc$(ObjectSuffix): pump.cc $(IntermediateDirectory)/pump.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/DezyneWorkspace/SensorTriggeredCamera/pump.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pump.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pump.cc$(DependSuffix): pump.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pump.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/pump.cc$(DependSuffix) -MM "pump.cc"

$(IntermediateDirectory)/pump.cc$(PreprocessSuffix): pump.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pump.cc$(PreprocessSuffix) "pump.cc"

$(IntermediateDirectory)/runtime.cc$(ObjectSuffix): runtime.cc $(IntermediateDirectory)/runtime.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/DezyneWorkspace/SensorTriggeredCamera/runtime.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/runtime.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/runtime.cc$(DependSuffix): runtime.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/runtime.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/runtime.cc$(DependSuffix) -MM "runtime.cc"

$(IntermediateDirectory)/runtime.cc$(PreprocessSuffix): runtime.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/runtime.cc$(PreprocessSuffix) "runtime.cc"

$(IntermediateDirectory)/PIRSensor.cc$(ObjectSuffix): PIRSensor.cc $(IntermediateDirectory)/PIRSensor.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/DezyneWorkspace/SensorTriggeredCamera/PIRSensor.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PIRSensor.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PIRSensor.cc$(DependSuffix): PIRSensor.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PIRSensor.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/PIRSensor.cc$(DependSuffix) -MM "PIRSensor.cc"

$(IntermediateDirectory)/PIRSensor.cc$(PreprocessSuffix): PIRSensor.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PIRSensor.cc$(PreprocessSuffix) "PIRSensor.cc"

$(IntermediateDirectory)/MotionTriggeredCam.cc$(ObjectSuffix): MotionTriggeredCam.cc $(IntermediateDirectory)/MotionTriggeredCam.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/DezyneWorkspace/SensorTriggeredCamera/MotionTriggeredCam.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MotionTriggeredCam.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MotionTriggeredCam.cc$(DependSuffix): MotionTriggeredCam.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MotionTriggeredCam.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/MotionTriggeredCam.cc$(DependSuffix) -MM "MotionTriggeredCam.cc"

$(IntermediateDirectory)/MotionTriggeredCam.cc$(PreprocessSuffix): MotionTriggeredCam.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MotionTriggeredCam.cc$(PreprocessSuffix) "MotionTriggeredCam.cc"

$(IntermediateDirectory)/Camera.cc$(ObjectSuffix): Camera.cc $(IntermediateDirectory)/Camera.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/DezyneWorkspace/SensorTriggeredCamera/Camera.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Camera.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Camera.cc$(DependSuffix): Camera.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Camera.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/Camera.cc$(DependSuffix) -MM "Camera.cc"

$(IntermediateDirectory)/Camera.cc$(PreprocessSuffix): Camera.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Camera.cc$(PreprocessSuffix) "Camera.cc"

$(IntermediateDirectory)/MotionTriggeredCameraSystem.cc$(ObjectSuffix): MotionTriggeredCameraSystem.cc $(IntermediateDirectory)/MotionTriggeredCameraSystem.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/DezyneWorkspace/SensorTriggeredCamera/MotionTriggeredCameraSystem.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MotionTriggeredCameraSystem.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MotionTriggeredCameraSystem.cc$(DependSuffix): MotionTriggeredCameraSystem.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MotionTriggeredCameraSystem.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/MotionTriggeredCameraSystem.cc$(DependSuffix) -MM "MotionTriggeredCameraSystem.cc"

$(IntermediateDirectory)/MotionTriggeredCameraSystem.cc$(PreprocessSuffix): MotionTriggeredCameraSystem.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MotionTriggeredCameraSystem.cc$(PreprocessSuffix) "MotionTriggeredCameraSystem.cc"

$(IntermediateDirectory)/timer.cc$(ObjectSuffix): timer.cc $(IntermediateDirectory)/timer.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/DezyneWorkspace/SensorTriggeredCamera/timer.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/timer.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/timer.cc$(DependSuffix): timer.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/timer.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/timer.cc$(DependSuffix) -MM "timer.cc"

$(IntermediateDirectory)/timer.cc$(PreprocessSuffix): timer.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/timer.cc$(PreprocessSuffix) "timer.cc"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/DezyneWorkspace/SensorTriggeredCamera/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


