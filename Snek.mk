##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Snek
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=/home/vidar/Dev/MOP/Sandbox
ProjectPath            :=/home/vidar/Dev/MOP/Sandbox/Snek
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Noak Palander
Date                   :=03/11/2023
CodeLitePath           :=/home/vidar/.codelite
LinkerName             :=/home/vidar/Dev/MOP/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-g++
SharedObjectLinkerName :=/home/vidar/Dev/MOP/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-g++ -shared -fPIC
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
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)SIMULATOR 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Snek.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -T$(ProjectPath)/md407-ram.x -L$(ARM_V6LIB) -L$(ARM_GCC_V6LIB) -nostartfiles -nostdlib
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)c_nano $(LibrarySwitch)gcc 
ArLibs                 :=  "c_nano" "gcc" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := /home/vidar/Dev/MOP/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-ar rcu
CXX      := /home/vidar/Dev/MOP/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-g++
CC       := /home/vidar/Dev/MOP/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-gcc
CXXFLAGS :=  -g -O0 -W $(Preprocessors)
CFLAGS   :=  -g -O0 -w -pedantic -Wextra -std=c99 -Wall -mthumb -march=armv6-m -mfloat-abi=soft $(Preprocessors)
ASFLAGS  := 
AS       := /home/vidar/Dev/MOP/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
ARM_V6LIB:=$(CodeLiteDir)/tools/gcc-arm/arm-none-eabi/lib/thumb/v6-m/nofp
ARM_GCC_V6LIB:=$(CodeLiteDir)/tools/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/thumb/v6-m/nofp
ARM_M4SFPLIB:=$(CodeLiteDir)/tools/gcc-arm/arm-none-eabi/lib/thumb/v7e-m+fp/softfp
ARM_GCC_M4SFPLIB:=$(CodeLiteDir)/tools/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/thumb/v7e-m+fp/softfp
ARM_M4HFPLIB:=$(CodeLiteDir)/tools/gcc-arm/arm-none-eabi/lib/thumb/v7e-m+fp/hard
ARM_GCC_M4HFPLIB:=$(CodeLiteDir)/tools/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/thumb/v7e-m+fp/hard
Objects0=$(IntermediateDirectory)/src_startup.c$(ObjectSuffix) $(IntermediateDirectory)/Utils_direction.c$(ObjectSuffix) $(IntermediateDirectory)/Utils_rng.c$(ObjectSuffix) $(IntermediateDirectory)/Utils_input.c$(ObjectSuffix) $(IntermediateDirectory)/Display_ascii.c$(ObjectSuffix) $(IntermediateDirectory)/Game_graphics.c$(ObjectSuffix) $(IntermediateDirectory)/Utils_pos.c$(ObjectSuffix) $(IntermediateDirectory)/Display_lcd.c$(ObjectSuffix) $(IntermediateDirectory)/Game_sprite.c$(ObjectSuffix) $(IntermediateDirectory)/Utils_delay.c$(ObjectSuffix) \
	$(IntermediateDirectory)/Game_snake.c$(ObjectSuffix) $(IntermediateDirectory)/src_mem.c$(ObjectSuffix) 



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

PostBuild:
	@echo Executing Post Build commands ...
	/usr/share/codelite/tools/gcc-arm/bin/arm-none-eabi-objcopy -S -O srec  Debug/Snek Debug/Snek.s19
	/usr/share/codelite/tools/gcc-arm/bin/arm-none-eabi-objdump -D -S Debug/Snek > Debug/Snek.lst
	@echo Done

MakeIntermediateDirs:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_startup.c$(ObjectSuffix): src/startup.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_startup.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_startup.c$(DependSuffix) -MM src/startup.c
	$(CC) $(SourceSwitch) "/home/vidar/Dev/MOP/Sandbox/Snek/src/startup.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_startup.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_startup.c$(PreprocessSuffix): src/startup.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_startup.c$(PreprocessSuffix) src/startup.c

$(IntermediateDirectory)/Utils_direction.c$(ObjectSuffix): Utils/direction.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Utils_direction.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Utils_direction.c$(DependSuffix) -MM Utils/direction.c
	$(CC) $(SourceSwitch) "/home/vidar/Dev/MOP/Sandbox/Snek/Utils/direction.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Utils_direction.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Utils_direction.c$(PreprocessSuffix): Utils/direction.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Utils_direction.c$(PreprocessSuffix) Utils/direction.c

$(IntermediateDirectory)/Utils_rng.c$(ObjectSuffix): Utils/rng.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Utils_rng.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Utils_rng.c$(DependSuffix) -MM Utils/rng.c
	$(CC) $(SourceSwitch) "/home/vidar/Dev/MOP/Sandbox/Snek/Utils/rng.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Utils_rng.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Utils_rng.c$(PreprocessSuffix): Utils/rng.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Utils_rng.c$(PreprocessSuffix) Utils/rng.c

$(IntermediateDirectory)/Utils_input.c$(ObjectSuffix): Utils/input.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Utils_input.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Utils_input.c$(DependSuffix) -MM Utils/input.c
	$(CC) $(SourceSwitch) "/home/vidar/Dev/MOP/Sandbox/Snek/Utils/input.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Utils_input.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Utils_input.c$(PreprocessSuffix): Utils/input.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Utils_input.c$(PreprocessSuffix) Utils/input.c

$(IntermediateDirectory)/Display_ascii.c$(ObjectSuffix): Display/ascii.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Display_ascii.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Display_ascii.c$(DependSuffix) -MM Display/ascii.c
	$(CC) $(SourceSwitch) "/home/vidar/Dev/MOP/Sandbox/Snek/Display/ascii.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Display_ascii.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Display_ascii.c$(PreprocessSuffix): Display/ascii.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Display_ascii.c$(PreprocessSuffix) Display/ascii.c

$(IntermediateDirectory)/Game_graphics.c$(ObjectSuffix): Game/graphics.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_graphics.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_graphics.c$(DependSuffix) -MM Game/graphics.c
	$(CC) $(SourceSwitch) "/home/vidar/Dev/MOP/Sandbox/Snek/Game/graphics.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_graphics.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_graphics.c$(PreprocessSuffix): Game/graphics.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_graphics.c$(PreprocessSuffix) Game/graphics.c

$(IntermediateDirectory)/Utils_pos.c$(ObjectSuffix): Utils/pos.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Utils_pos.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Utils_pos.c$(DependSuffix) -MM Utils/pos.c
	$(CC) $(SourceSwitch) "/home/vidar/Dev/MOP/Sandbox/Snek/Utils/pos.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Utils_pos.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Utils_pos.c$(PreprocessSuffix): Utils/pos.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Utils_pos.c$(PreprocessSuffix) Utils/pos.c

$(IntermediateDirectory)/Display_lcd.c$(ObjectSuffix): Display/lcd.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Display_lcd.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Display_lcd.c$(DependSuffix) -MM Display/lcd.c
	$(CC) $(SourceSwitch) "/home/vidar/Dev/MOP/Sandbox/Snek/Display/lcd.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Display_lcd.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Display_lcd.c$(PreprocessSuffix): Display/lcd.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Display_lcd.c$(PreprocessSuffix) Display/lcd.c

$(IntermediateDirectory)/Game_sprite.c$(ObjectSuffix): Game/sprite.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_sprite.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_sprite.c$(DependSuffix) -MM Game/sprite.c
	$(CC) $(SourceSwitch) "/home/vidar/Dev/MOP/Sandbox/Snek/Game/sprite.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_sprite.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_sprite.c$(PreprocessSuffix): Game/sprite.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_sprite.c$(PreprocessSuffix) Game/sprite.c

$(IntermediateDirectory)/Utils_delay.c$(ObjectSuffix): Utils/delay.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Utils_delay.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Utils_delay.c$(DependSuffix) -MM Utils/delay.c
	$(CC) $(SourceSwitch) "/home/vidar/Dev/MOP/Sandbox/Snek/Utils/delay.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Utils_delay.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Utils_delay.c$(PreprocessSuffix): Utils/delay.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Utils_delay.c$(PreprocessSuffix) Utils/delay.c

$(IntermediateDirectory)/Game_snake.c$(ObjectSuffix): Game/snake.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_snake.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_snake.c$(DependSuffix) -MM Game/snake.c
	$(CC) $(SourceSwitch) "/home/vidar/Dev/MOP/Sandbox/Snek/Game/snake.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_snake.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_snake.c$(PreprocessSuffix): Game/snake.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_snake.c$(PreprocessSuffix) Game/snake.c

$(IntermediateDirectory)/src_mem.c$(ObjectSuffix): src/mem.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_mem.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_mem.c$(DependSuffix) -MM src/mem.c
	$(CC) $(SourceSwitch) "/home/vidar/Dev/MOP/Sandbox/Snek/src/mem.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_mem.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_mem.c$(PreprocessSuffix): src/mem.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_mem.c$(PreprocessSuffix) src/mem.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


