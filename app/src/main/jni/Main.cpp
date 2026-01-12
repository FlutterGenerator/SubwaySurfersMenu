#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"
#include "KittyMemory/MemoryPatch.h"
//#include "And64InlineHook/And64InlineHook.hpp"
#include "Includes/Chams.h"
#include  "Menu.h"

//#include <Substrate/SubstrateHook.h>
//#include <Substrate/CydiaSubstrate.h>

//Целевая библиотека здесь
#define targetLibName OBFUSCATE("libil2cpp.so")

// Усовершенствованная структура для патчей для kittyMemory
структура  My_Patches  {
    // Предположим, у нас есть патчи для этих функций для какой-либо игры
    // как показано в булевой функции miniMap
    MemoryPatch  Displace , AddCoins , AddKeys , AddPoints , Get_BaseMultiplierSum , AddItemSources , Motor_OnLowerImpact , Get_Stumble , Motor_OnLaneChangeFrontalImpac , Motor_OnSideImpact , Motor_OnFrontalImpact , Kill , ProcessAbilities , WorldReposition , Get_JumpHeight , Get_AirJumpHeight , Get_LaneChangeDuration , GetSurfaceKind , Get_Gravity , Get_JumpLimit , ForceCustomJump , StickToGround , ApplyGravity , Get_NoCornerCollision , Get_MinSpeedAbilities , Get_MaxSpeed , Get_MaxSpeedAbilities ;
	// и т. д...
} hexPatches;

bool feature2 = false , featureHookToggle = false , chams, shading, wireframe, glow, outline, rainbow = false;false;
int sliderValue = 1, level = 0; sliderValue = 1, level = 0;
void *instanceBtn; *instanceBtn;

// Указатель на функцию разделен, потому что мы хотим избежать сбоя, если библиотека il2cpp не загружена.
// Если вы укажете getAbsoluteAddress здесь, библиотека попытается прочитать адрес без загруженного il2cpp.
// приведет к созданию нулевого указателя, что вызовет сбой
// См. https://guidedhacking.com/threads/android-function-pointers-hooking-template-tutorial.14771/
void (*AddMoneyExample)(void *instance, int amount); (*AddMoneyExample)(void *instance, int amount);

// Мы будем запускать наши патчи в новом потоке, чтобы наш цикл while не блокировал основной поток процесса.
// Не забудьте удалить или закомментировать строки логов перед компиляцией.

//Пример использования KittyMemory в Android: https://github.com/MJx0/KittyMemory/blob/master/Android/test/src/main.cpp
//Используйте ARM Converter для преобразования ARM в HEX: https://armconverter.com/
//Примечание: Для смещений мы используем OBFUSCATE_KEY, это важная часть xD

/*bool Ismod = false;

/*bool Ismod = false;
bool mod(void *instance) {
    if (instance != NULL && Ismod) {
          return false;
    }
    return old_mod(instance);
}*/

// Пример использования хуков. Пожалуйста, обратитесь к онлайн-урокам по настройке хуков.
bool (*old_get_BoolExample)(void *instance); (*old_get_BoolExample)(void *instance);
 get_BoolExample(void *instance) { get_BoolExample(void *instance) {
    if (instance != NULL && featureHookToggle) {if (instance != NULL && featureHookToggle) {
        вернуть true;return true;
    }}
    return old_get_BoolExample(instance);return old_get_BoolExample(instance);
}

float (*old_get_FloatExample)(void *instance); (*old_get_FloatExample)(void *instance);
float get_FloatExample(void *instance) { get_FloatExample(void *instance) {
    if (instance != NULL && sliderValue > 1) {if (instance != NULL && sliderValue > 1) {
        return (float) sliderValue;return (float) sliderValue;
    }}
    return old_get_FloatExample(instance);return old_get_FloatExample(instance);
}

int (*old_Level)(void *instance); (*old_Level)(void *instance);
int Level(void *instance) { Level(void *instance) {
    if (instance != NULL && level) { if  ( instance != NULL && level )  {
         
    }
     
}
	instanceBtn = instance;
}

void 
    ProcMap il2cppMap;
    делать  {
        il2cppMap = KittyMemory:: getLibraryMap ( targetLibName ) ;
        )
      
    )
    LogShaders();
    Wallhack();
    
    //Check if target lib is loaded
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));

    //Anti-lib rename
    /*
    do {
        sleep(1);
    } while (!isLibraryLoaded("libYOURNAME.so"));*/

    LOGI(OBFUSCATE("%s has been loaded"), (const char *) targetLibName);

#if defined(__aarch64__) //Compile for arm64 lib only

// A64HookFunction((void *)getAbsoluteAddress("libil2cpp.so", Hook), (void *)mod, (void **) &old_mod);
    
#endif //Compile for armv7 lib only. Do not worry about greyed out highlighting code, it still works

    // New way to patch hex via KittyMemory without need to specify len. Spaces or without spaces are fine
    // ARMv7 assembly example
    // MOV R0, #0x0 = 00 00 A0 E3
    // BX LR = 1E FF 2F E1
hexPatches.Displace = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                        string2Offset(OBFUSCATE("0xB05480")),
                                                        OBFUSCATE("79 04 44 E3 1E FF 2F E1"));
                                                    
                                                    
hexPatches.AddCoins = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                        string2Offset(OBFUSCATE("0x972218")),
                                                        OBFUSCATE("A0 00 44 E3 1E FF 2E E1"));
                                                    
                                                    
hexPatches.AddKeys = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                       string2Offset(OBFUSCATE("0x9722C8")),
                                                       OBFUSCATE("02 01 E0 E3 1E FF 2F E1"));
                                                    
hexPatches.AddPoints = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                         string2Offset(OBFUSCATE("0x972638")),
                                                         OBFUSCATE("0A 00 A0 E3 1E FF 2F E1"));						
                                                   
    
hexPatches.Get_BaseMultiplierSum = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                                     string2Offset(OBFUSCATE("0xB3D8C4")),
                                                                     OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));			
                                                    
                                                    
hexPatches.AddItemSources = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                              string2Offset(OBFUSCATE("0xB3E19C")),
                                                              OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));			


hexPatches.Motor_OnLowerImpact = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                                   string2Offset(OBFUSCATE("0xBCAB80")),
                                                                   OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));			
                                                                   
hexPatches.Get_Stumble = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                           string2Offset(OBFUSCATE("0xBC96D4")),
                                                           OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));			
                                                                                           
hexPatches.Motor_OnLaneChangeFrontalImpac = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                                              string2Offset(OBFUSCATE("0xBCAE3C")),
                                                                              OBFUSCATE("C8 02 44 E3 1E FF 2F E1"));			
                                                                                                          
hexPatches.Motor_OnSideImpact = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                                  string2Offset(OBFUSCATE("0xBCAEB4")),
                                                                  OBFUSCATE("0F 07 02 E3 1E FF 2F E1"));		
   
hexPatches.Motor_OnFrontalImpact = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                    string2Offset(OBFUSCATE("0xBCAF2C")),
                                                    OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));			
                                                                                                          
hexPatches.Kill = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                    string2Offset(OBFUSCATE("0xBCB00C")),
                                                    OBFUSCATE("00 00 A0 E3 1E FF 2F E1"));		
   
hexPatches.ProcessAbilities = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                    string2Offset(OBFUSCATE("0xBCD600")),
                                                    OBFUSCATE("00 00 40 E3 1E FF 2F E1"));			
                                                                                                          
hexPatches.WorldReposition = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                       string2Offset(OBFUSCATE("0xA4E7D0")),
                                                       OBFUSCATE("FA 04 44 E3 1E FF 2F E1"));		
													   
hexPatches.Get_JumpHeight = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                       string2Offset(OBFUSCATE("0x8AD938")),
                                                       OBFUSCATE("00 7A F7 EE 90 1A 17 EE"));	
													
hexPatches.Get_AirJumpHeight = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                       string2Offset(OBFUSCATE("0x8AD948")),
                                                       OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));		
													
hexPatches.Get_LaneChangeDuration = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                             string2Offset(OBFUSCATE("0x8BC158")),
                                                             OBFUSCATE("00 00 A0 E3 1E FF 2F E1"));		
													
hexPatches.GetSurfaceKind = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                        string2Offset(OBFUSCATE("0xBCF754")),
                                                        OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));		
													
hexPatches.Get_Gravity = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                         string2Offset(OBFUSCATE("0xBCFAD4")),
                                                         OBFUSCATE("00 00 E0 E3 1E FF 2F E1"));		
													
hexPatches.Get_JumpLimit = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                     string2Offset(OBFUSCATE("0xBCFEA4")),
                                                     OBFUSCATE("00 00 E0 E3 1E FF 2F E1"));		
                                                    
hexPatches.ForceCustomJump = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                      string2Offset(OBFUSCATE("0xBCE664")),
                                                      OBFUSCATE("00 00 A0 E3 1E FF 2F E1"));		
													
hexPatches.StickToGround = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                     string2Offset(OBFUSCATE("0xBD1A5C")),
                                                     OBFUSCATE("00 00 E0 E3 1E FF 2F E1"));		      	
													
hexPatches.ApplyGravity = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                        string2Offset(OBFUSCATE("0xBD2118")),
                                                        OBFUSCATE("00 00 E0 E3 1E FF 2F E1"));		      	     
													
hexPatches.Get_NoCornerCollision = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                         string2Offset(OBFUSCATE("0xBD2708")),
                                                         OBFUSCATE("00 00 E0 E3 1E FF 2F E1"));		      	
													
hexPatches.Get_MinSpeedAbilities = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                       string2Offset(OBFUSCATE("0xBD2F7C")),
                                                       OBFUSCATE("FA 04 44 E3 1E FF 2F E1"));	
													
hexPatches.Get_MaxSpeed = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                      string2Offset(OBFUSCATE("0xBD316C")),
                                                      OBFUSCATE("00 00 E0 E3 1E FF 2F E1"));	                                                
                                                    	             	             
hexPatches.Get_MaxSpeedAbilities = MemoryPatch::createWithHex(targetLibName, //Normal obfuscate
                                                   string2Offset(OBFUSCATE("0xBD31AC")),
                                                   OBFUSCATE("00 F0 20 E3 00 F0 20 E3"));		
													
							
    LOGI(OBFUSCATE("Done"));

    return NULL;
}

//JNI calls
extern "C" {
// Note:
// Do not change or translate the first text unless you know what you are doing
// Assigning feature numbers is optional. Without it, it will automatically count for you, starting from 0
// Assigned feature numbers can be like any numbers 1,3,200,10... instead in order 0,1,2,3,4,5...
// ButtonLink, Category, RichTextView and RichWebView is not counted. They can't have feature number assigned
// Toggle, Toggle and Checkbox can be switched on by default, if you add True_. Example: CheckBox_True_The Check Box
// To learn HTML, go to this page: https://www.w3schools.com/

JNIEXPORT jobjectArray
JNICALL
Java_uk_lgl_modmenu_FloatingModMenuService_getFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;

    //Toasts added here so it's harder to remove it
    MakeToast(env, context, OBFUSCATE("〘MOD MENU BY RAPINRO〙"), Toast::LENGTH_LONG);

    const char *features[] = {
            //Create new collapse
			OBFUSCATE("Category_〘SUBWAY SURF〙〘3.13.2〙"), //Not counted
            OBFUSCATE("Toggle_Displace️"),//1 Case
            OBFUSCATE("Toggle_AddCoins"),//2 Case
            OBFUSCATE("Toggle_AddKeys"),//3 Case
			OBFUSCATE("Toggle_MotorOnFrontalImpact️"),//11 Case
            OBFUSCATE("Toggle_Kill"),//12 Case
            OBFUSCATE("Toggle_ProcessAbilities"),//13 Case
//Create new collapse
            OBFUSCATE("Collapse_〘PLAYER〙〘HACK〙"),//Not counted
            OBFUSCATE("CollapseAdd_Toggle_AddPoints"),//4 Case
            OBFUSCATE("CollapseAdd_Toggle_BaseMultiplierSum"),//5 Case
            OBFUSCATE("CollapseAdd_Toggle_AddItemSources"),//6 Case
            OBFUSCATE("CollapseAdd_Toggle_MotorOnLowerImpact"),//7 Case
            OBFUSCATE("CollapseAdd_Toggle_Stumble"),//8 Case
            OBFUSCATE("CollapseAdd_Toggle_MotorOnLaneChangeFrontalImpac"),//9 Case
            OBFUSCATE("CollapseAdd_Toggle_MotorOnSideImpact"),//10 Case
//Create new collapse         
            OBFUSCATE("Toggle_WorldReposition"),//14 Case
            OBFUSCATE("Toggle_JumpHeight️"),//15 Case
            OBFUSCATE("Toggle_AirJumpHeight️"),//16 Case
            OBFUSCATE("Toggle_LaneChangeDuration"),//17 Case
            OBFUSCATE("Toggle_SurfaceKind"),//18 Case
            OBFUSCATE("Toggle_Gravity"),//19 Case
			OBFUSCATE("Collapse_〘JAMP〙〘GRAVITY〙〘SPEED〙"),//Not counted
            OBFUSCATE("CollapseAdd_Toggle_JumpLimit️"),//20 Case
            OBFUSCATE("CollapseAdd_Toggle_ForceCustomJump️"),//21 Case
            OBFUSCATE("CollapseAdd_Toggle_StickToGround"),//22 Case
            OBFUSCATE("CollapseAdd_Toggle_ApplyGravity"),//23 Case
            OBFUSCATE("CollapseAdd_Toggle_NoCornerCollision"),//24 Case
            OBFUSCATE("CollapseAdd_Toggle_MinSpeedAbilities"),//25 Case
            OBFUSCATE("CollapseAdd_Toggle_MaxSpeed"),//26 Case
            OBFUSCATE("CollapseAdd_Toggle_MaxSpeedAbilities"),//27 Case
            OBFUSCATE("Category_〘Chams〙〘Menu〙"), //Not Counted
            OBFUSCATE("ButtonOnOff_Default Chams"), //28 Case
            OBFUSCATE("ButtonOnOff_Wireframe Chams"), //29 Case
            OBFUSCATE("ButtonOnOff_Glow Chams"), //30 Case
            OBFUSCATE("ButtonOnOff_Outline Chams"), //31 Case
            OBFUSCATE("ButtonOnOff_Rainbow Chams"), //32 Case
            OBFUSCATE("Category_〘FOR MORE〙"), //Not counted
            OBFUSCATE("ButtonLink_VISIT MY BLOGSPOT_https://elementman50.blogspot.com"), //Not counted       
            
            OBFUSCATE("RichWebView_<html><head><style>body{color: white;}</style></head><body>"
                      "<marquee style=\"color: red; font-weight:bold;\" direction=\"left\" scrollamount=\"5\" behavior=\"scroll\">This is Mod is made by <u>亗𝐑𝐀𝐏𝐈𝐍𝐑𝐎亗</u> VISIT OUR WEB FOR MORE UPDATES</marquee>"
                      "</body></html>")
    };


    //Now you dont have to manually update the number everytime;
    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    pthread_t ptid;
    pthread_create(&ptid, NULL, antiLeech, NULL);

    return (ret);
}

JNIEXPORT void JNICALL
Java_uk_lgl_modmenu_Preferences_Changes(JNIEnv *env, jclass clazz, jobject obj,
                                        jint featNum, jstring featName, jint value,
                                        jboolean boolean, jstring str) {
    //Convert java string to c++
    const char *featureName = env->GetStringUTFChars(featName, 0);
    const char *TextInput;
    if (str != NULL)
        TextInput = env->GetStringUTFChars(str, 0);
    else
        TextInput = "Empty";

    LOGD(OBFUSCATE("Feature name: %d - %s | Value: = %d | Bool: = %d | Text: = %s"), featNum,
         featureName, value,
         boolean, TextInput);

    //BE CAREFUL NOT TO ACCIDENTLY REMOVE break;

    switch (featNum) {
      case 1:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Displace.Modify();
            } else {
                hexPatches.Displace.Restore();
            }
            break;
      case 2:
            feature2 = boolean;
            if (feature2) {
                hexPatches.AddCoins.Modify();
            } else {
                hexPatches.AddCoins.Restore();
            }
            break;    
      case 3:
            feature2 = boolean;
            if (feature2) {
                hexPatches.AddKeys.Modify();
            } else {
                hexPatches.AddKeys.Restore();
            }
            break;
      case 4:
            feature2 = boolean;
            if (feature2) {
                hexPatches.AddPoints.Modify();
            } else {
                hexPatches.AddPoints.Restore();
            }
            break;
      case 5:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Get_BaseMultiplierSum.Modify();
            } else {
                hexPatches.Get_BaseMultiplierSum.Restore();
            }
            break;         
      case 6:
            feature2 = boolean;
            if (feature2) {
                hexPatches.AddItemSources.Modify();
            } else {
                hexPatches.AddItemSources.Restore();
            }
            break;         
      case 7:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Motor_OnLowerImpact.Modify();
            } else {
                hexPatches.Motor_OnLowerImpact.Restore();
            }
            break; 
      case 8:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Get_Stumble.Modify();
            } else {
                hexPatches.Get_Stumble.Restore();
            }
            break; 
      case 9:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Motor_OnLaneChangeFrontalImpac.Modify();
            } else {
                hexPatches.Motor_OnLaneChangeFrontalImpac.Restore();
            }
            break; 
     case 10:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Motor_OnSideImpact.Modify();
            } else {
                hexPatches.Motor_OnSideImpact.Restore();
            }
            break; 
     case 11:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Motor_OnFrontalImpact.Modify();
            } else {
                hexPatches.Motor_OnFrontalImpact.Restore();
            }
            break; 
     case 12:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Kill.Modify();
            } else {
                hexPatches.Kill.Restore();
            }
            break; 
     case 13:
            feature2 = boolean;
            if (feature2) {
                hexPatches.ProcessAbilities.Modify();
            } else {
                hexPatches.ProcessAbilities.Restore();
            }
            break; 
     case 14:
            feature2 = boolean;
            if (feature2) {
                hexPatches.WorldReposition.Modify();
            } else {
                hexPatches.WorldReposition.Restore();
            }
            break; 
     case 15:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Get_JumpHeight.Modify();
            } else {
                hexPatches.Get_JumpHeight.Restore();
            }
            break; 
     case 16:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Get_AirJumpHeight.Modify();
            } else {
                hexPatches.Get_AirJumpHeight.Restore();
            }
            break; 
     case 17:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Get_LaneChangeDuration.Modify();
            } else {
                hexPatches.Get_LaneChangeDuration.Restore();
            }
            break; 
     case 18:
            feature2 = boolean;
            if (feature2) {
                hexPatches.GetSurfaceKind.Modify();
            } else {
                hexPatches.GetSurfaceKind.Restore();
            }
            break; 
     case 19:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Get_Gravity.Modify();
            } else {
                hexPatches.Get_Gravity.Restore();
            }
            break; 
     case 20:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Get_JumpLimit.Modify();
            } else {
                hexPatches.Get_JumpLimit.Restore();
            }
            break; 
     case 21:
            feature2 = boolean;
            if (feature2) {
                hexPatches.ForceCustomJump.Modify();
            } else {
                hexPatches.ForceCustomJump.Restore();
            }
            break;          
     case 22:
            feature2 = boolean;
            if (feature2) {
                hexPatches.StickToGround.Modify();
            } else {
                hexPatches.StickToGround.Restore();
            }
            break;                  
     case 23:
            feature2 = boolean;
            if (feature2) {
                hexPatches.ApplyGravity.Modify();
            } else {
                hexPatches.ApplyGravity.Restore();
            }
            break;                    
     case 24:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Get_NoCornerCollision.Modify();
            } else {
                hexPatches.Get_NoCornerCollision.Restore();
            }
            break;                  
     case 25:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Get_MinSpeedAbilities.Modify();
            } else {
                hexPatches.Get_MinSpeedAbilities.Restore();
            }
            break;                    
     case 26:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Get_MaxSpeed.Modify();
            } else {
                hexPatches.Get_MaxSpeed.Restore();
            }
            break;                    
     case 27:
            feature2 = boolean;
            if (feature2) {
                hexPatches.Get_MaxSpeedAbilities.Modify();
            } else {
                hexPatches.Get_MaxSpeedAbilities.Restore();
            }
            break;
     case 28:
            SetWallhack(boolean);
            break;
     case 29:
            SetWallhackW(boolean);
            break;
     case 30:
            SetWallhackG(boolean);
            break;
     case 31:
            SetWallhackO(boolean);
            break;
     case 32:
            SetRainbow(boolean);
            break;            
}
}
}

//No need to use JNI_OnLoad, since we don't use JNIEnv
//We do this to hide OnLoad from disassembler
__attribute__((constructor))
void lib_main() {
    // Create a new thread so it does not block the main thread, means the game would not freeze
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}

/*
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *globalEnv;
    vm->GetEnv((void **) &globalEnv, JNI_VERSION_1_6);
    return JNI_VERSION_1_6;
}
 */
