// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME nanoDict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "src/AliJCDijetHistos.h"
#include "src/AliJHistogramInterface.h"
#include "src/AliJHistManager.h"
#include "src/AliJBaseTrack.h"
#include "src/AliJBaseCard.h"
#include "src/AliJCard.h"
#include "src/AliJPhoton.h"
#include "src/AliJJet.h"
#include "src/JHistos.h"
#include "src/JTreeDataManager.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *AliJHistManager_Dictionary();
   static void AliJHistManager_TClassManip(TClass*);
   static void delete_AliJHistManager(void *p);
   static void deleteArray_AliJHistManager(void *p);
   static void destruct_AliJHistManager(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AliJHistManager*)
   {
      ::AliJHistManager *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::AliJHistManager));
      static ::ROOT::TGenericClassInfo 
         instance("AliJHistManager", "src/AliJHistManager.h", 386,
                  typeid(::AliJHistManager), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &AliJHistManager_Dictionary, isa_proxy, 0,
                  sizeof(::AliJHistManager) );
      instance.SetDelete(&delete_AliJHistManager);
      instance.SetDeleteArray(&deleteArray_AliJHistManager);
      instance.SetDestructor(&destruct_AliJHistManager);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AliJHistManager*)
   {
      return GenerateInitInstanceLocal((::AliJHistManager*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::AliJHistManager*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *AliJHistManager_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::AliJHistManager*)0x0)->GetClass();
      AliJHistManager_TClassManip(theClass);
   return theClass;
   }

   static void AliJHistManager_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *AliJHistogramInterface_Dictionary();
   static void AliJHistogramInterface_TClassManip(TClass*);
   static void delete_AliJHistogramInterface(void *p);
   static void deleteArray_AliJHistogramInterface(void *p);
   static void destruct_AliJHistogramInterface(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AliJHistogramInterface*)
   {
      ::AliJHistogramInterface *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::AliJHistogramInterface));
      static ::ROOT::TGenericClassInfo 
         instance("AliJHistogramInterface", "src/AliJHistogramInterface.h", 41,
                  typeid(::AliJHistogramInterface), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &AliJHistogramInterface_Dictionary, isa_proxy, 0,
                  sizeof(::AliJHistogramInterface) );
      instance.SetDelete(&delete_AliJHistogramInterface);
      instance.SetDeleteArray(&deleteArray_AliJHistogramInterface);
      instance.SetDestructor(&destruct_AliJHistogramInterface);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AliJHistogramInterface*)
   {
      return GenerateInitInstanceLocal((::AliJHistogramInterface*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::AliJHistogramInterface*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *AliJHistogramInterface_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::AliJHistogramInterface*)0x0)->GetClass();
      AliJHistogramInterface_TClassManip(theClass);
   return theClass;
   }

   static void AliJHistogramInterface_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *AliJBaseCard_Dictionary();
   static void AliJBaseCard_TClassManip(TClass*);
   static void *new_AliJBaseCard(void *p = 0);
   static void *newArray_AliJBaseCard(Long_t size, void *p);
   static void delete_AliJBaseCard(void *p);
   static void deleteArray_AliJBaseCard(void *p);
   static void destruct_AliJBaseCard(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AliJBaseCard*)
   {
      ::AliJBaseCard *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::AliJBaseCard));
      static ::ROOT::TGenericClassInfo 
         instance("AliJBaseCard", "src/AliJBaseCard.h", 31,
                  typeid(::AliJBaseCard), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &AliJBaseCard_Dictionary, isa_proxy, 0,
                  sizeof(::AliJBaseCard) );
      instance.SetNew(&new_AliJBaseCard);
      instance.SetNewArray(&newArray_AliJBaseCard);
      instance.SetDelete(&delete_AliJBaseCard);
      instance.SetDeleteArray(&deleteArray_AliJBaseCard);
      instance.SetDestructor(&destruct_AliJBaseCard);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AliJBaseCard*)
   {
      return GenerateInitInstanceLocal((::AliJBaseCard*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::AliJBaseCard*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *AliJBaseCard_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::AliJBaseCard*)0x0)->GetClass();
      AliJBaseCard_TClassManip(theClass);
   return theClass;
   }

   static void AliJBaseCard_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *AliJBaseTrack_Dictionary();
   static void AliJBaseTrack_TClassManip(TClass*);
   static void *new_AliJBaseTrack(void *p = 0);
   static void *newArray_AliJBaseTrack(Long_t size, void *p);
   static void delete_AliJBaseTrack(void *p);
   static void deleteArray_AliJBaseTrack(void *p);
   static void destruct_AliJBaseTrack(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AliJBaseTrack*)
   {
      ::AliJBaseTrack *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::AliJBaseTrack));
      static ::ROOT::TGenericClassInfo 
         instance("AliJBaseTrack", "src/AliJBaseTrack.h", 33,
                  typeid(::AliJBaseTrack), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &AliJBaseTrack_Dictionary, isa_proxy, 0,
                  sizeof(::AliJBaseTrack) );
      instance.SetNew(&new_AliJBaseTrack);
      instance.SetNewArray(&newArray_AliJBaseTrack);
      instance.SetDelete(&delete_AliJBaseTrack);
      instance.SetDeleteArray(&deleteArray_AliJBaseTrack);
      instance.SetDestructor(&destruct_AliJBaseTrack);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AliJBaseTrack*)
   {
      return GenerateInitInstanceLocal((::AliJBaseTrack*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::AliJBaseTrack*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *AliJBaseTrack_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::AliJBaseTrack*)0x0)->GetClass();
      AliJBaseTrack_TClassManip(theClass);
   return theClass;
   }

   static void AliJBaseTrack_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *AliJPhoton_Dictionary();
   static void AliJPhoton_TClassManip(TClass*);
   static void *new_AliJPhoton(void *p = 0);
   static void *newArray_AliJPhoton(Long_t size, void *p);
   static void delete_AliJPhoton(void *p);
   static void deleteArray_AliJPhoton(void *p);
   static void destruct_AliJPhoton(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AliJPhoton*)
   {
      ::AliJPhoton *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::AliJPhoton));
      static ::ROOT::TGenericClassInfo 
         instance("AliJPhoton", "src/AliJPhoton.h", 28,
                  typeid(::AliJPhoton), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &AliJPhoton_Dictionary, isa_proxy, 0,
                  sizeof(::AliJPhoton) );
      instance.SetNew(&new_AliJPhoton);
      instance.SetNewArray(&newArray_AliJPhoton);
      instance.SetDelete(&delete_AliJPhoton);
      instance.SetDeleteArray(&deleteArray_AliJPhoton);
      instance.SetDestructor(&destruct_AliJPhoton);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AliJPhoton*)
   {
      return GenerateInitInstanceLocal((::AliJPhoton*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::AliJPhoton*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *AliJPhoton_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::AliJPhoton*)0x0)->GetClass();
      AliJPhoton_TClassManip(theClass);
   return theClass;
   }

   static void AliJPhoton_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *AliJCard_Dictionary();
   static void AliJCard_TClassManip(TClass*);
   static void *new_AliJCard(void *p = 0);
   static void *newArray_AliJCard(Long_t size, void *p);
   static void delete_AliJCard(void *p);
   static void deleteArray_AliJCard(void *p);
   static void destruct_AliJCard(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AliJCard*)
   {
      ::AliJCard *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::AliJCard));
      static ::ROOT::TGenericClassInfo 
         instance("AliJCard", "src/AliJCard.h", 42,
                  typeid(::AliJCard), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &AliJCard_Dictionary, isa_proxy, 0,
                  sizeof(::AliJCard) );
      instance.SetNew(&new_AliJCard);
      instance.SetNewArray(&newArray_AliJCard);
      instance.SetDelete(&delete_AliJCard);
      instance.SetDeleteArray(&deleteArray_AliJCard);
      instance.SetDestructor(&destruct_AliJCard);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AliJCard*)
   {
      return GenerateInitInstanceLocal((::AliJCard*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::AliJCard*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *AliJCard_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::AliJCard*)0x0)->GetClass();
      AliJCard_TClassManip(theClass);
   return theClass;
   }

   static void AliJCard_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *AliJCDijetHistos_Dictionary();
   static void AliJCDijetHistos_TClassManip(TClass*);
   static void delete_AliJCDijetHistos(void *p);
   static void deleteArray_AliJCDijetHistos(void *p);
   static void destruct_AliJCDijetHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AliJCDijetHistos*)
   {
      ::AliJCDijetHistos *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::AliJCDijetHistos));
      static ::ROOT::TGenericClassInfo 
         instance("AliJCDijetHistos", "src/AliJCDijetHistos.h", 30,
                  typeid(::AliJCDijetHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &AliJCDijetHistos_Dictionary, isa_proxy, 0,
                  sizeof(::AliJCDijetHistos) );
      instance.SetDelete(&delete_AliJCDijetHistos);
      instance.SetDeleteArray(&deleteArray_AliJCDijetHistos);
      instance.SetDestructor(&destruct_AliJCDijetHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AliJCDijetHistos*)
   {
      return GenerateInitInstanceLocal((::AliJCDijetHistos*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::AliJCDijetHistos*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *AliJCDijetHistos_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::AliJCDijetHistos*)0x0)->GetClass();
      AliJCDijetHistos_TClassManip(theClass);
   return theClass;
   }

   static void AliJCDijetHistos_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *AliJJet_Dictionary();
   static void AliJJet_TClassManip(TClass*);
   static void *new_AliJJet(void *p = 0);
   static void *newArray_AliJJet(Long_t size, void *p);
   static void delete_AliJJet(void *p);
   static void deleteArray_AliJJet(void *p);
   static void destruct_AliJJet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AliJJet*)
   {
      ::AliJJet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::AliJJet));
      static ::ROOT::TGenericClassInfo 
         instance("AliJJet", "src/AliJJet.h", 35,
                  typeid(::AliJJet), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &AliJJet_Dictionary, isa_proxy, 0,
                  sizeof(::AliJJet) );
      instance.SetNew(&new_AliJJet);
      instance.SetNewArray(&newArray_AliJJet);
      instance.SetDelete(&delete_AliJJet);
      instance.SetDeleteArray(&deleteArray_AliJJet);
      instance.SetDestructor(&destruct_AliJJet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AliJJet*)
   {
      return GenerateInitInstanceLocal((::AliJJet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::AliJJet*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *AliJJet_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::AliJJet*)0x0)->GetClass();
      AliJJet_TClassManip(theClass);
   return theClass;
   }

   static void AliJJet_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *JHistos_Dictionary();
   static void JHistos_TClassManip(TClass*);
   static void *new_JHistos(void *p = 0);
   static void *newArray_JHistos(Long_t size, void *p);
   static void delete_JHistos(void *p);
   static void deleteArray_JHistos(void *p);
   static void destruct_JHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JHistos*)
   {
      ::JHistos *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::JHistos));
      static ::ROOT::TGenericClassInfo 
         instance("JHistos", "src/JHistos.h", 23,
                  typeid(::JHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &JHistos_Dictionary, isa_proxy, 0,
                  sizeof(::JHistos) );
      instance.SetNew(&new_JHistos);
      instance.SetNewArray(&newArray_JHistos);
      instance.SetDelete(&delete_JHistos);
      instance.SetDeleteArray(&deleteArray_JHistos);
      instance.SetDestructor(&destruct_JHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JHistos*)
   {
      return GenerateInitInstanceLocal((::JHistos*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::JHistos*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *JHistos_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::JHistos*)0x0)->GetClass();
      JHistos_TClassManip(theClass);
   return theClass;
   }

   static void JHistos_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *JTreeDataManager_Dictionary();
   static void JTreeDataManager_TClassManip(TClass*);
   static void *new_JTreeDataManager(void *p = 0);
   static void *newArray_JTreeDataManager(Long_t size, void *p);
   static void delete_JTreeDataManager(void *p);
   static void deleteArray_JTreeDataManager(void *p);
   static void destruct_JTreeDataManager(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JTreeDataManager*)
   {
      ::JTreeDataManager *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::JTreeDataManager));
      static ::ROOT::TGenericClassInfo 
         instance("JTreeDataManager", "src/JTreeDataManager.h", 36,
                  typeid(::JTreeDataManager), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &JTreeDataManager_Dictionary, isa_proxy, 0,
                  sizeof(::JTreeDataManager) );
      instance.SetNew(&new_JTreeDataManager);
      instance.SetNewArray(&newArray_JTreeDataManager);
      instance.SetDelete(&delete_JTreeDataManager);
      instance.SetDeleteArray(&deleteArray_JTreeDataManager);
      instance.SetDestructor(&destruct_JTreeDataManager);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JTreeDataManager*)
   {
      return GenerateInitInstanceLocal((::JTreeDataManager*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::JTreeDataManager*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *JTreeDataManager_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::JTreeDataManager*)0x0)->GetClass();
      JTreeDataManager_TClassManip(theClass);
   return theClass;
   }

   static void JTreeDataManager_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_AliJHistManager(void *p) {
      delete ((::AliJHistManager*)p);
   }
   static void deleteArray_AliJHistManager(void *p) {
      delete [] ((::AliJHistManager*)p);
   }
   static void destruct_AliJHistManager(void *p) {
      typedef ::AliJHistManager current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AliJHistManager

namespace ROOT {
   // Wrapper around operator delete
   static void delete_AliJHistogramInterface(void *p) {
      delete ((::AliJHistogramInterface*)p);
   }
   static void deleteArray_AliJHistogramInterface(void *p) {
      delete [] ((::AliJHistogramInterface*)p);
   }
   static void destruct_AliJHistogramInterface(void *p) {
      typedef ::AliJHistogramInterface current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AliJHistogramInterface

namespace ROOT {
   // Wrappers around operator new
   static void *new_AliJBaseCard(void *p) {
      return  p ? new(p) ::AliJBaseCard : new ::AliJBaseCard;
   }
   static void *newArray_AliJBaseCard(Long_t nElements, void *p) {
      return p ? new(p) ::AliJBaseCard[nElements] : new ::AliJBaseCard[nElements];
   }
   // Wrapper around operator delete
   static void delete_AliJBaseCard(void *p) {
      delete ((::AliJBaseCard*)p);
   }
   static void deleteArray_AliJBaseCard(void *p) {
      delete [] ((::AliJBaseCard*)p);
   }
   static void destruct_AliJBaseCard(void *p) {
      typedef ::AliJBaseCard current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AliJBaseCard

namespace ROOT {
   // Wrappers around operator new
   static void *new_AliJBaseTrack(void *p) {
      return  p ? new(p) ::AliJBaseTrack : new ::AliJBaseTrack;
   }
   static void *newArray_AliJBaseTrack(Long_t nElements, void *p) {
      return p ? new(p) ::AliJBaseTrack[nElements] : new ::AliJBaseTrack[nElements];
   }
   // Wrapper around operator delete
   static void delete_AliJBaseTrack(void *p) {
      delete ((::AliJBaseTrack*)p);
   }
   static void deleteArray_AliJBaseTrack(void *p) {
      delete [] ((::AliJBaseTrack*)p);
   }
   static void destruct_AliJBaseTrack(void *p) {
      typedef ::AliJBaseTrack current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AliJBaseTrack

namespace ROOT {
   // Wrappers around operator new
   static void *new_AliJPhoton(void *p) {
      return  p ? new(p) ::AliJPhoton : new ::AliJPhoton;
   }
   static void *newArray_AliJPhoton(Long_t nElements, void *p) {
      return p ? new(p) ::AliJPhoton[nElements] : new ::AliJPhoton[nElements];
   }
   // Wrapper around operator delete
   static void delete_AliJPhoton(void *p) {
      delete ((::AliJPhoton*)p);
   }
   static void deleteArray_AliJPhoton(void *p) {
      delete [] ((::AliJPhoton*)p);
   }
   static void destruct_AliJPhoton(void *p) {
      typedef ::AliJPhoton current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AliJPhoton

namespace ROOT {
   // Wrappers around operator new
   static void *new_AliJCard(void *p) {
      return  p ? new(p) ::AliJCard : new ::AliJCard;
   }
   static void *newArray_AliJCard(Long_t nElements, void *p) {
      return p ? new(p) ::AliJCard[nElements] : new ::AliJCard[nElements];
   }
   // Wrapper around operator delete
   static void delete_AliJCard(void *p) {
      delete ((::AliJCard*)p);
   }
   static void deleteArray_AliJCard(void *p) {
      delete [] ((::AliJCard*)p);
   }
   static void destruct_AliJCard(void *p) {
      typedef ::AliJCard current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AliJCard

namespace ROOT {
   // Wrapper around operator delete
   static void delete_AliJCDijetHistos(void *p) {
      delete ((::AliJCDijetHistos*)p);
   }
   static void deleteArray_AliJCDijetHistos(void *p) {
      delete [] ((::AliJCDijetHistos*)p);
   }
   static void destruct_AliJCDijetHistos(void *p) {
      typedef ::AliJCDijetHistos current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AliJCDijetHistos

namespace ROOT {
   // Wrappers around operator new
   static void *new_AliJJet(void *p) {
      return  p ? new(p) ::AliJJet : new ::AliJJet;
   }
   static void *newArray_AliJJet(Long_t nElements, void *p) {
      return p ? new(p) ::AliJJet[nElements] : new ::AliJJet[nElements];
   }
   // Wrapper around operator delete
   static void delete_AliJJet(void *p) {
      delete ((::AliJJet*)p);
   }
   static void deleteArray_AliJJet(void *p) {
      delete [] ((::AliJJet*)p);
   }
   static void destruct_AliJJet(void *p) {
      typedef ::AliJJet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AliJJet

namespace ROOT {
   // Wrappers around operator new
   static void *new_JHistos(void *p) {
      return  p ? new(p) ::JHistos : new ::JHistos;
   }
   static void *newArray_JHistos(Long_t nElements, void *p) {
      return p ? new(p) ::JHistos[nElements] : new ::JHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_JHistos(void *p) {
      delete ((::JHistos*)p);
   }
   static void deleteArray_JHistos(void *p) {
      delete [] ((::JHistos*)p);
   }
   static void destruct_JHistos(void *p) {
      typedef ::JHistos current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JHistos

namespace ROOT {
   // Wrappers around operator new
   static void *new_JTreeDataManager(void *p) {
      return  p ? new(p) ::JTreeDataManager : new ::JTreeDataManager;
   }
   static void *newArray_JTreeDataManager(Long_t nElements, void *p) {
      return p ? new(p) ::JTreeDataManager[nElements] : new ::JTreeDataManager[nElements];
   }
   // Wrapper around operator delete
   static void delete_JTreeDataManager(void *p) {
      delete ((::JTreeDataManager*)p);
   }
   static void deleteArray_JTreeDataManager(void *p) {
      delete [] ((::JTreeDataManager*)p);
   }
   static void destruct_JTreeDataManager(void *p) {
      typedef ::JTreeDataManager current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JTreeDataManager

namespace {
  void TriggerDictionaryInitialization_nanoDict_Impl() {
    static const char* headers[] = {
"src/AliJCDijetHistos.h",
"src/AliJHistogramInterface.h",
"src/AliJHistManager.h",
"src/AliJBaseTrack.h",
"src/AliJBaseCard.h",
"src/AliJCard.h",
"src/AliJPhoton.h",
"src/AliJJet.h",
"src/JHistos.h",
"src/JTreeDataManager.h",
0
    };
    static const char* includePaths[] = {
"/home/maxim/root/include/",
"/home/maxim/Documents/Työt/CMS-opendata/pythiacode_for_cms_edit/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "nanoDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$src/AliJCDijetHistos.h")))  AliJHistManager;
class __attribute__((annotate("$clingAutoload$src/AliJCDijetHistos.h")))  AliJHistogramInterface;
class __attribute__((annotate("$clingAutoload$src/AliJCDijetHistos.h")))  AliJBaseCard;
class __attribute__((annotate("$clingAutoload$src/AliJCDijetHistos.h")))  AliJBaseTrack;
class __attribute__((annotate("$clingAutoload$src/AliJCDijetHistos.h")))  AliJPhoton;
class __attribute__((annotate("$clingAutoload$src/AliJCDijetHistos.h")))  AliJCard;
class __attribute__((annotate("$clingAutoload$src/AliJCDijetHistos.h")))  AliJCDijetHistos;
class __attribute__((annotate("$clingAutoload$src/AliJJet.h")))  AliJJet;
class __attribute__((annotate("$clingAutoload$src/JHistos.h")))  JHistos;
class __attribute__((annotate("$clingAutoload$src/JTreeDataManager.h")))  JTreeDataManager;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "nanoDict dictionary payload"

#ifndef JTKT
  #define JTKT 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "src/AliJCDijetHistos.h"
#include "src/AliJHistogramInterface.h"
#include "src/AliJHistManager.h"
#include "src/AliJBaseTrack.h"
#include "src/AliJBaseCard.h"
#include "src/AliJCard.h"
#include "src/AliJPhoton.h"
#include "src/AliJJet.h"
#include "src/JHistos.h"
#include "src/JTreeDataManager.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"AliJBaseCard", payloadCode, "@",
"AliJBaseTrack", payloadCode, "@",
"AliJCDijetHistos", payloadCode, "@",
"AliJCard", payloadCode, "@",
"AliJHistManager", payloadCode, "@",
"AliJHistogramInterface", payloadCode, "@",
"AliJJet", payloadCode, "@",
"AliJPhoton", payloadCode, "@",
"JHistos", payloadCode, "@",
"JTreeDataManager", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("nanoDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_nanoDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_nanoDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_nanoDict() {
  TriggerDictionaryInitialization_nanoDict_Impl();
}
