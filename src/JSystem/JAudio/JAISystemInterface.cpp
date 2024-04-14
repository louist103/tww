//
// Generated by dtk
// Translation Unit: JAISystemInterface.cpp
//

#include "JSystem/JAudio/JAISystemInterface.h"
#include "JSystem/JAudio/JASTrack.h"
#include "dolphin/dvd/dvd.h"

JASystem::Kernel::TPortCmd JAInter::SystemInterface::systemPortCmd;

/* 8029E188-8029E1B4       .text checkFileExsistence__Q27JAInter15SystemInterfaceFPc */
BOOL JAInter::SystemInterface::checkFileExsistence(char* param_1) {
    if (DVDConvertPathToEntrynum(param_1) != -1)
        return TRUE;
    else
        return FALSE;
}

/* 8029E1B4-8029E2A0       .text checkSeqActiveFlag__Q27JAInter15SystemInterfaceFPQ28JASystem6TTrack */
int JAInter::SystemInterface::checkSeqActiveFlag(JASystem::TTrack* param_1) {
    if (param_1 && param_1->field_0x37e) {
        if (param_1->mChildren[0] || param_1->mChildren[1] || param_1->mChildren[2] || param_1->mChildren[3] ||
            param_1->mChildren[4] || param_1->mChildren[5] || param_1->mChildren[6] || param_1->mChildren[7] ||
            param_1->mChildren[8] || param_1->mChildren[9] || param_1->mChildren[10] || param_1->mChildren[11] ||
            param_1->mChildren[12] || param_1->mChildren[13] || param_1->mChildren[14] || param_1->mChildren[15]
        ) {
            return param_1->field_0x37e;
        }
        return 0;
    }
    return 0;
}

/* 8029E2A0-8029E478       .text trackToSeqp__Q27JAInter15SystemInterfaceFP8JAISoundUc */
void JAInter::SystemInterface::trackToSeqp(JAISound*, u8) {
    /* Nonmatching */
}

/* 8029E478-8029E494       .text setSeqPortargsF32__Q27JAInter15SystemInterfaceFPQ27JAInter13SeqUpdateDataUlUcf */
void JAInter::SystemInterface::setSeqPortargsF32(JAInter::SeqUpdateData*, u32, u8, f32) {
    /* Nonmatching */
}

/* 8029E494-8029E4B0       .text setSeqPortargsU32__Q27JAInter15SystemInterfaceFPQ27JAInter13SeqUpdateDataUlUcUl */
void JAInter::SystemInterface::setSeqPortargsU32(JAInter::SeqUpdateData*, u32, u8, u32) {
    /* Nonmatching */
}

/* 8029E4B0-8029E518       .text rootInit__Q27JAInter15SystemInterfaceFPQ27JAInter13SeqUpdateData */
void JAInter::SystemInterface::rootInit(JAInter::SeqUpdateData*) {
    /* Nonmatching */
}

/* 8029E518-8029E5B4       .text trackInit__Q27JAInter15SystemInterfaceFPQ27JAInter13SeqUpdateData */
void JAInter::SystemInterface::trackInit(JAInter::SeqUpdateData*) {
    /* Nonmatching */
}

/* 8029E5B4-8029E7B8       .text outerInit__Q27JAInter15SystemInterfaceFPQ27JAInter13SeqUpdateDataPvUlUsUc */
void JAInter::SystemInterface::outerInit(JAInter::SeqUpdateData*, void*, u32, u16, u8) {
    /* Nonmatching */
}

/* 8029E7B8-8029E820       .text setPortParameter__Q27JAInter15SystemInterfaceFPQ38JASystem6Kernel9TPortArgsPQ28JASystem6TTrackUlUl */
void JAInter::SystemInterface::setPortParameter(JASystem::Kernel::TPortArgs*, JASystem::TTrack*, u32, u32) {
    /* Nonmatching */
}

/* 8029E820-8029E8F4       .text setSePortParameter__Q27JAInter15SystemInterfaceFPQ38JASystem6Kernel9TPortArgs */
void JAInter::SystemInterface::setSePortParameter(JASystem::Kernel::TPortArgs*) {
    /* Nonmatching */
}
