//
// Generated by dtk
// Translation Unit: JASBasicWaveBank.cpp
//

#include "JSystem/JAudio/JASBasicWaveBank.h"
#include "JSystem/JAudio/JASCalc.h"
#include "JSystem/JKernel/JKRSolidHeap.h"
#include "JSystem/JUtility/JUTAssert.h"

/* 80285968-802859C8       .text __ct__Q28JASystem14TBasicWaveBankFv */
JASystem::TBasicWaveBank::TBasicWaveBank() {
    mWaveTable = NULL;
    mWaveCount = 0;
    mWaveGroupArray = NULL;
    mWaveGroupCount = 0;
    OSInitMutex(&mMutex);
}

/* 802859C8-80285A74       .text __dt__Q28JASystem14TBasicWaveBankFv */
JASystem::TBasicWaveBank::~TBasicWaveBank() {
    delete[] mWaveTable;
    for (int i = 0; i < mWaveGroupCount; i++) {
        delete mWaveGroupArray[i];
    }
    delete[] mWaveGroupArray;
}

/* 80285A74-80285AFC       .text getWaveGroup__Q28JASystem14TBasicWaveBankFi */
JASystem::TBasicWaveBank::TWaveGroup* JASystem::TBasicWaveBank::getWaveGroup(int group_no) {
    JUT_ASSERT(41, group_no >= 0);
    if (group_no >= mWaveGroupCount) {
        return NULL;
    }
    return mWaveGroupArray[group_no];
}

/* 80285AFC-80285C10       .text setGroupCount__Q28JASystem14TBasicWaveBankFUl */
void JASystem::TBasicWaveBank::setGroupCount(u32 param_1) {
    for (int i = 0; i < mWaveGroupCount; i++) {
        delete mWaveGroupArray[i];
    }
    delete[] mWaveGroupArray;
    mWaveGroupCount = param_1;
    mWaveGroupArray = new (getCurrentHeap(), 0) TWaveGroup*[param_1];
    JUT_ASSERT(58, mWaveGroupArray != 0);
    for (int i = 0; i < mWaveGroupCount; i++) {
        mWaveGroupArray[i] = new (getCurrentHeap(), 0) TWaveGroup(this);
    }
}

/* 80285C10-80285CB0       .text setWaveTableSize__Q28JASystem14TBasicWaveBankFUl */
void JASystem::TBasicWaveBank::setWaveTableSize(u32 param_1) {
    delete[] mWaveTable;
    mWaveTable = new (getCurrentHeap(), 0) TWaveInfo*[param_1];
    JUT_ASSERT(70, mWaveTable != 0);
    Calc::bzero(mWaveTable, param_1 * 4);
    mWaveCount = param_1;
}

/* 80285CB0-80285D54       .text incWaveTable__Q28JASystem14TBasicWaveBankFPCQ38JASystem14TBasicWaveBank10TWaveGroup */
void JASystem::TBasicWaveBank::incWaveTable(const TWaveGroup* param_1) {
    /* Nonmatching */
    OSLockMutex(&mMutex);
    for (int i = 0; i < param_1->mWaveCount; i++) {
        u32 waveID = param_1->getWaveID(i);
        TWaveInfo** table = mWaveTable;
        TWaveInfo* waveInfo = &param_1->mCtrlWaveArray[i];
        waveInfo->field_0x3c = 0;
        waveInfo->field_0x38 = table[waveID];
        if (table[waveID]) {
            table[waveID]->field_0x3c = waveInfo;
        }
        table[waveID] = waveInfo;
    }
    OSUnlockMutex(&mMutex);
}

/* 80285D54-80285E28       .text decWaveTable__Q28JASystem14TBasicWaveBankFPCQ38JASystem14TBasicWaveBank10TWaveGroup */
void JASystem::TBasicWaveBank::decWaveTable(const TWaveGroup*) {
    /* Nonmatching */
}

/* 80285E28-80285E58       .text getWaveHandle__Q28JASystem14TBasicWaveBankCFUl */
JASystem::TWaveHandle* JASystem::TBasicWaveBank::getWaveHandle(u32 param_1) const {
    if (param_1 >= mWaveCount) {
        return NULL;
    }
    if (mWaveTable[param_1]) {
        return &mWaveTable[param_1]->field_0x0;
    }
    return NULL;
}

/* 80285E58-80285EB0       .text __ct__Q38JASystem14TBasicWaveBank10TWaveGroupFPQ28JASystem14TBasicWaveBank */
JASystem::TBasicWaveBank::TWaveGroup::TWaveGroup(TBasicWaveBank* param_1) {
    mBank = param_1;
    mCtrlWaveArray = NULL;
    mWaveCount = 0;
}

/* 80285EB0-80285F64       .text __dt__Q38JASystem14TBasicWaveBank10TWaveGroupFv */
JASystem::TBasicWaveBank::TWaveGroup::~TWaveGroup() {
    delete[] mCtrlWaveArray;
}

/* 80285F64-80285FC4       .text __dt__Q38JASystem14TBasicWaveBank9TWaveInfoFv */
JASystem::TBasicWaveBank::TWaveInfo::~TWaveInfo() {}

/* 80285FC4-802860B8       .text setWaveCount__Q38JASystem14TBasicWaveBank10TWaveGroupFUl */
void JASystem::TBasicWaveBank::TWaveGroup::setWaveCount(u32 param_1) {
    delete[] mCtrlWaveArray;
    mWaveCount = param_1;
    mCtrlWaveArray = new (getCurrentHeap(), 0) TWaveInfo[param_1];
    JUT_ASSERT(180, mCtrlWaveArray != 0);
    for (int i = 0; i < param_1; i++) {
        mCtrlWaveArray[i].field_0x0.mHeap = &field_0x4;
        mCtrlWaveArray[i].field_0x0.field_0x4.field_0x24 = &field_0x4c;
    }
}

/* 802860B8-80286204       .text setWaveInfo__Q38JASystem14TBasicWaveBank10TWaveGroupFiUlRCQ28JASystem9TWaveInfo */
void JASystem::TBasicWaveBank::TWaveGroup::setWaveInfo(int index, u32 param_2, const JASystem::TWaveInfo& param_3) {
    JUT_ASSERT(190, index < mWaveCount);
    JUT_ASSERT(191, index >= 0);
    mCtrlWaveArray[index].field_0x34 = param_2;
    mCtrlWaveArray[index].field_0x0.field_0x4 = param_3;
    mCtrlWaveArray[index].field_0x0.field_0x4.field_0x24 = &field_0x4c;
}

/* 80286204-80286274       .text onLoadDone__Q38JASystem14TBasicWaveBank10TWaveGroupFv */
void JASystem::TBasicWaveBank::TWaveGroup::onLoadDone() {
    JUT_ASSERT(201, mBank);
    mBank->incWaveTable(this);
}

/* 80286274-802862E4       .text onEraseDone__Q38JASystem14TBasicWaveBank10TWaveGroupFv */
void JASystem::TBasicWaveBank::TWaveGroup::onEraseDone() {
    JUT_ASSERT(207, mBank);
    mBank->decWaveTable(this);
}

/* 802862E4-802862F8       .text getWaveID__Q38JASystem14TBasicWaveBank10TWaveGroupCFi */
u32 JASystem::TBasicWaveBank::TWaveGroup::getWaveID(int param_1) const {
    return mCtrlWaveArray[param_1].field_0x34;
}
