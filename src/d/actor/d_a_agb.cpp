//
// Generated by dtk
// Translation Unit: d_a_agb.cpp
//

#include "d/actor/d_a_agb.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "JSystem/JUtility/JUTGba.h"
#include "d/actor/d_a_player_link.h"
#include "d/d_bg_s_lin_chk.h"
#include "d/d_com_inf_game.h"
#include "d/d_item_data.h"
#include "d/d_meter.h"
#include "d/d_procname.h"
#include "m_Do/m_Do_controller_pad.h"
#include "m_Do/m_Do_dvd_thread.h"
#include "m_Do/m_Do_gba_com.h"
#include "m_Do/m_Do_mtx.h"

// stripped or compiler generated?
static u32 unused_lit_2100[] = {0x3F800000, 0x3F800000, 0x3F800000,
                                0x3F800000, 0x3F800000, 0x3F800000};

// temp
class daNpc_Md_c {
public:
    static bool m_flying;
};

class daNpc_Cb1_c {
public:
    static bool m_flying;
};

class daBomb_c {
public:
    enum State_e {
        STATE_8_e = 8,
    };

    static u32 prm_make(State_e, bool, bool);
};

static mDoDvdThd_toMainRam_c* l_gbaCommand;

int daAgb_c::mEffect;
u8 daAgb_c::mItemBuy;
daAgb_c::daAgb_GbaFlg daAgb_c::mGbaFlg;
daAgb_c::daAgb_Switch daAgb_c::mSwitch;
daAgb_c::daAgb_Item daAgb_c::mItem;
u8 daAgb_c::mShop;

/* 800CF5EC-800CF6B8       .text __ct__11daAgb_HIO_cFv */
daAgb_HIO_c::daAgb_HIO_c() {
    field_0x04[0].mColor.r = 0;
    field_0x04[0].mColor.g = 255;
    field_0x04[0].mColor.b = 0;
    field_0x04[0].mColor.a = 255;

    field_0x04[1].mColor.r = 0;
    field_0x04[1].mColor.g = 30;
    field_0x04[1].mColor.b = 0;
    field_0x04[1].mColor.a = 0;

    field_0x14 = 24.0f;
    field_0x18 = 50.0f;
    field_0x1c = 781.25f;
    field_0x20 = 170.0f;
    field_0x24 = 0.0f;
    field_0x28 = 5.0f;
    field_0x2c = 10.0f;
    field_0x30 = 15.0f;
}

static daAgb_HIO_c l_HIO;

/* 800CF700-800CF71C       .text init__10dMsgCtrl_cFUs */
int dMsgCtrl_c::init(u16 param_0) {
    field_0x0 = param_0;
    mMsgID = -1;
    mpMsg = NULL;
    return 1;
}

/* 800CF71C-800CF7B4       .text execute__10dMsgCtrl_cFv */
int dMsgCtrl_c::execute() {
    if (mMsgID == -1) {
        mMsgID = fopMsgM_messageSet(field_0x0);
    } else if (mpMsg == NULL) {
        mpMsg = fopMsgM_SearchByID(mMsgID);
    } else {
        if (mpMsg->mMode == 18) {
            mpMsg->mMode = 19;
            dComIfGp_event_onEventFlag(8);
        }

        return mpMsg->mMode;
    }

    return -1;
}

static dMsgCtrl_c l_msgCtrl;

/* 800CF7B4-800CF7F8       .text sjis2chrNo__FUc */
u8 sjis2chrNo(u8 i_chr) {
    static u8 l_sjis2chrNo[] = {
        ' ',  'A',  'B',  'C',  'D',  'E',  'F',  'G',  'H',  'I',  'J',  'K',  'L',  'M',  'N',
        'O',  'P',  'Q',  'R',  'S',  'T',  'U',  'V',  'W',  'X',  'Y',  'Z',  'a',  'b',  'c',
        'd',  'e',  'f',  'g',  'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',  'p',  'q',  'r',
        's',  't',  'u',  'v',  'w',  'x',  'y',  'z',  '0',  '1',  '2',  '3',  '4',  '5',  '6',
        '7',  '8',  '9',  ' ',  0xf8, 0xd8, 0xfe, 0xde, 0x9c, 0x8c, 0xe6, 0xc6, 0xf0, 0xd0, 0xc7,
        0xe7, 0xdf, ' ',  ' ',  '+',  0xbf, 0xa1, 0xab, 0xbb, 0x84, 0x93, '!',  ' ',  '-',  '?',
        ' ',  ' ',  '(',  ')',  ' ',  '.',  ' ',  0xd7, 0xf7, '\'', '\"', 0x85, '/',  0xc0, 0xc8,
        0xcc, 0xd2, 0xd9, 0xe0, 0xe8, 0xec, 0xf2, 0xf9, 0xc1, 0xc9, 0xcd, 0xd3, 0xda, 0xdd, 0xe1,
        0xe9, 0xed, 0xf3, 0xfa, 0xfd, 0xc2, 0xca, 0xce, 0xd4, 0xdb, 0xe2, 0xea, 0xee, 0xf4, 0xfb,
        0xc3, 0xd1, 0xd5, 0xe3, 0xf1, 0xf5, 0xc4, 0xcb, 0xcf, 0xd6, 0xdc, 0x9f, 0xe4, 0xeb, 0xef,
        0xf6, 0xfc, 0xff, 0xc5, 0xe5, 0x8a, 0x9a, 0xba, 0xaa,
    };

    for (u8 i = 0; i < 159; i++) {
        if (i_chr == l_sjis2chrNo[i]) {
            return i;
        }
    }

    return 0xFF;
}

/* 800CF7F8-800CF894       .text NameConv__7daAgb_cFv */
void daAgb_c::NameConv() {
    int i;
    const char* name = dComIfGs_getPlayerName();
    mPlayerName = 0;

    for (i = 0; i < 8; i++) {
        u8 chr = sjis2chrNo(*name);
        mPlayerName |= chr;
        name++;

        if (i < 7) {
            mPlayerName <<= 8;
        }
    }
}

/* 800CF894-800CFA30       .text uploadInitCheck__7daAgb_cFv */
int daAgb_c::uploadInitCheck() {
    s32 roomNo = dComIfGp_roomControl_getStayNo();
    dStage_FileList_dt_c* fili_p =
        dComIfGp_roomControl_getStatusRoomDt(roomNo)->getFileListInfo();

    if ((dStage_stagInfo_GetSTType(dComIfGp_getStageStagInfo()) != 7 &&
         !dMap_c::isEnableDispMap()) ||
        (fili_p != NULL && (fili_p->mParam & 2)))
    {
        l_msgCtrl.init(1);
        mUploadAction = 10;
    } else if (g_mDoGaC_gbaCom.field_0x0 == 0) {
        field_0x66f = 0;
        field_0x678 = 0;
        JUTGba::getManager()->doInitProbe(1, NULL, NULL);
        JUTGba::getManager()->doInitProbe(2, NULL, NULL);
        JUTGba::getManager()->doInitProbe(3, NULL, NULL);
        mUploadAction = 1;
    } else if (g_mDoGaC_gbaCom.mDoGaC_GbaLink()) {
        l_msgCtrl.init(2);
        mUploadAction = 10;
    } else {
        JUTGba::getManager()->doInitProbe(1, NULL, NULL);
        JUTGba::getManager()->doInitProbe(2, NULL, NULL);
        JUTGba::getManager()->doInitProbe(3, NULL, NULL);
        mUploadAction = 1;
        g_mDoGaC_gbaCom.mDoGaC_ConnectSleep();
    }

    return 1;
}

/* 800CFA30-800CFB68       .text uploadPortCheckWait__7daAgb_cFv */
int daAgb_c::uploadPortCheckWait() {
    u32 sp14[3];
    int sp8[3];

    for (int i = 0; i < 3; i++) {
        sp8[i] = JUTGba::getManager()->resultInitProbe(i + 1, &sp14[i]);
        if (sp8[i] == -2) {
            return 1;
        }
    }

    if (g_mDoGaC_gbaCom.mDoGaC_GbaLink()) {
        l_msgCtrl.init(2);
        mUploadAction = 10;
    } else {
        for (int i = 0; i < 3; i++) {
            if (sp8[i] == 0 && sp14[i] == 0x40000) {
                mPortNo = i + 1;
                l_msgCtrl.init(5);
                mUploadAction = 2;
                return 1;
            }
        }

        l_msgCtrl.init(3);
        mUploadAction = 10;
        g_mDoGaC_gbaCom.mDoGaC_ConnectWake();
    }

    return 1;
}

extern JKRHeap* dMsg_getAgbWorkArea();

/* 800CFB68-800CFC94       .text uploadSelect__7daAgb_cFv */
int daAgb_c::uploadSelect() {
    if (l_msgCtrl.execute() == 14) {
        if (dComIfGp_checkMesgCancelButton() || (int)l_msgCtrl.mpMsg->mSelectedChoiceIdx != 0) {
            l_msgCtrl.mpMsg->mMode = 16;
            g_mDoGaC_gbaCom.mDoGaC_ConnectWake();
        } else {
            l_msgCtrl.mpMsg->mMode = 15;
            fopMsgM_messageSet(6);  // "Now calling Tingle..."
            mUploadAction = 3;

            l_gbaCommand =
                mDoDvdThd_toMainRam_c::create("/res/Gba/client_u.bin", 0, dMsg_getAgbWorkArea());
            JUT_ASSERT(860, l_gbaCommand != 0);

            g_mDoGaC_gbaCom.mDoGaC_GbaReboot();
            g_mDoGaC_gbaCom.mPortNo = mPortNo;
            field_0x66f = 0;
            field_0x678 = 0;
        }
    }

    return 1;
}

/* 800CFC94-800CFD60       .text uploadJoyboot1__7daAgb_cFv */
int daAgb_c::uploadJoyboot1() {
    if (l_gbaCommand->sync()) {
        void* programp = l_gbaCommand->getMemAddress();
        JUT_ASSERT(891, programp != 0);

        JUTGba::getManager()->doJoyBoot(mDoGaC_getPortNo(), 3, -1, (u8*)programp,
                                        l_gbaCommand->getMemSize() - 4, NULL, NULL);
        mUploadAction = 4;
        field_0x664 = 450;
    }

    return 1;
}

/* 800CFD60-800CFEA0       .text uploadJoyboot2__7daAgb_cFv */
int daAgb_c::uploadJoyboot2() {
    u8 sp8[16];

    int result = JUTGba::getManager()->resultJoyBoot(mDoGaC_getPortNo(), sp8);
    if (result != -2) {
        JKRHeap::free(l_gbaCommand->getMemAddress(), NULL);
        delete l_gbaCommand;

        if (result == 0) {
            field_0x664 = 15;
            mUploadAction = 6;
        } else {
            l_msgCtrl.mpMsg->mMode = 15;
            fopMsgM_messageSet(7);  // "An error has occurred."
            fopMsgM_messageSendOn();
            mUploadAction = 10;
        }
    } else {
        field_0x664--;
        if (field_0x664 == 0) {
            l_msgCtrl.mpMsg->mMode = 15;
            fopMsgM_messageSet(7);  // "An error has occurred."
            fopMsgM_messageSendOn();
            mUploadAction = 10;

            JKRHeap::free(l_gbaCommand->getMemAddress(), NULL);
            delete l_gbaCommand;
        }
    }

    return 1;
}

/* 800CFEA0-800CFF58       .text uploadMessageLoad__7daAgb_cFv */
int daAgb_c::uploadMessageLoad() {
    field_0x664--;
    if (field_0x664 == 0) {
        l_gbaCommand = mDoDvdThd_toMainRam_c::create("/res/Gba/msg_LZ.bin", 0, NULL);
        JUT_ASSERT(1000, l_gbaCommand != 0);

        mUploadAction = 7;
        g_mDoGaC_gbaCom.field_0x0 = 1;
        g_mDoGaC_gbaCom.mDoGaC_ComStart();
    }

    return 1;
}

/* 800CFF58-800CFF78       .text uploadMessageLoad2__7daAgb_cFv */
int daAgb_c::uploadMessageLoad2() {
    if (l_gbaCommand->sync()) {
        mUploadAction = 5;
    }

    return 1;
}

/* 800CFF78-800D00C8       .text uploadConnect__7daAgb_cFv */
int daAgb_c::uploadConnect() {
    if (g_mDoGaC_gbaCom.field_0x0 != 0 && g_mDoGaC_gbaCom.mDoGaC_GbaLink()) {
        void* programp = l_gbaCommand->getMemAddress();
        JUT_ASSERT(1045, programp != 0);
        g_mDoGaC_gbaCom.mDoGaC_SendDataSet((u32*)programp, l_gbaCommand->getMemSize(), 0, 0);

        mUploadAction = 8;
        NameConv();
        g_mDoGaC_gbaCom.mDoGaC_SendDataSet((u32*)&mPlayerName, sizeof(mPlayerName), 10, 0);

        dMap_c::mapAGBSendIslandData();
    } else {
        g_mDoGaC_gbaCom.mDoGaC_GbaReboot();
        l_msgCtrl.mpMsg->mMode = 15;
        fopMsgM_messageSet(7);  // "An error has occurred."
        fopMsgM_messageSendOn();
        mUploadAction = 10;

        JKRHeap::free(l_gbaCommand->getMemAddress(), NULL);
        delete l_gbaCommand;
    }

    return 1;
}

/* 800D00C8-800D01F4       .text uploadMessageSend__7daAgb_cFv */
int daAgb_c::uploadMessageSend() {
    if (g_mDoGaC_gbaCom.field_0x110->field_0x4 == 0) {
        field_0x678 = 1;
        if (field_0x67a != 0) {
            l_msgCtrl.mpMsg->mMode = 15;
            fopMsgM_messageSet(8);  // "Tingle appeared on your Game Boy Advance!"
            fopMsgM_messageSendOn();
            mUploadAction = 11;
            field_0x664 = 60;

            dComIfGs_onEventBit(0x1A20);
            dComIfGp_particle_set(0x2E7, &current.pos, NULL, NULL, 255, &field_0x684);

            JKRHeap::free(l_gbaCommand->getMemAddress(), NULL);
            delete l_gbaCommand;
        }
    } else if (g_mDoGaC_gbaCom.field_0x110->field_0x4 == 9) {
        field_0x664 = 5;
        mUploadAction = 9;
    }

    return 1;
}

/* 800D01F4-800D021C       .text uploadRetryWait__7daAgb_cFv */
int daAgb_c::uploadRetryWait() {
    field_0x664--;
    if (field_0x664 == 0) {
        mUploadAction = 5;
    }

    return 1;
}

/* 800D021C-800D0264       .text uploadMsgEndWait__7daAgb_cFv */
int daAgb_c::uploadMsgEndWait() {
    if (l_msgCtrl.execute() == 14) {
        l_msgCtrl.mpMsg->mMode = 16;
    }

    return 1;
}

/* 800D0264-800D02E8       .text uploadMsgEndTimer__7daAgb_cFv */
int daAgb_c::uploadMsgEndTimer() {
    l_msgCtrl.execute();
    if (field_0x664 != 0) {
        field_0x664--;

        if (field_0x664 == 0) {
            l_msgCtrl.mpMsg->mMode = 16;
            fopMsgM_messageSendOn();
        } else if (field_0x664 == 30) {
            field_0x66f = 1;
        }
    }

    return 1;
}

daAgb_c::uploadFunc daAgb_c::uploadFuncTable[] = {
    &daAgb_c::uploadInitCheck,   &daAgb_c::uploadPortCheckWait, &daAgb_c::uploadSelect,
    &daAgb_c::uploadJoyboot1,    &daAgb_c::uploadJoyboot2,      &daAgb_c::uploadConnect,
    &daAgb_c::uploadMessageLoad, &daAgb_c::uploadMessageLoad2,  &daAgb_c::uploadMessageSend,
    &daAgb_c::uploadRetryWait,   &daAgb_c::uploadMsgEndWait,    &daAgb_c::uploadMsgEndTimer,
};

/* 800D02E8-800D0364       .text modeLoad__7daAgb_cFv */
void daAgb_c::modeLoad() {
    if (mEvtInfo.checkCommandTalk()) {
        uploadFunc func = uploadFuncTable[mUploadAction];
        (this->*func)();
    } else {
        mUploadAction = 0;
        mEvtInfo.onCondition(dEvtCnd_CANTALK_e);
        mMode = 0;
    }
}

/* 800D0364-800D0490       .text modeLookAttention__7daAgb_cFv */
void daAgb_c::modeLookAttention() {
    static bool se_flag = false;

    if (mEvtInfo.checkCommandDemoAccrpt()) {
        if (!se_flag) {
            fopAcM_seStart(this, JA_SE_CV_CHI_MEGAHORN, 0);
            se_flag = true;
        }

        if (dComIfGp_evmng_endCheck("DEFAULT_AGB_LOOK_ATTENTION")) {
            dComIfGp_event_onEventFlag(8);
            mMode = 0;
            se_flag = false;

            field_0x65c = 1;
            if (field_0x674 == 0) {
                shape_angle.x = 0;
                shape_angle.y = 0;
                shape_angle.z = 0;
                field_0x628 = 2.5f;
            }
        }
    } else {
        fopAcM_orderOtherEvent2(this, "DEFAULT_AGB_LOOK_ATTENTION", 4, 0xFFFF);
    }
}

u8 daAgb_c::DungeonNoTable[] = {
    0, 11, 11, 1, 2, 3, 4, 5, 17, 17, 17, 17, 17, 17, 17, 17,
};

/* 800D0490-800D0580       .text DungeonNoGet__7daAgb_cFv */
u8 daAgb_c::DungeonNoGet() {
    u8 var_r0 = DungeonNoTable[field_0x66c];

    u8 dungeon_no = var_r0;
    if (dungeon_no == 0) {
        if (field_0x67e != 0) {
            switch (field_0x66d) {
            case 1:
                dungeon_no = 10;
                break;
            case 11:
                dungeon_no = 6;
                break;
            case 13:
                dungeon_no = 7;
                break;
            case 41:
                dungeon_no = 8;
                break;
            case 44:
                dungeon_no = 9;
                break;
            case 4:
                dungeon_no = 14;
                break;
            case 20:
                dungeon_no = 15;
                break;
            case 23:
                dungeon_no = 12;
                break;
            case 40:
                dungeon_no = 16;
                break;
            case 45:
                dungeon_no = 13;
                break;
            }
        }

        if (field_0x66d != field_0x66e) {
            resetCursor(true);
        }
    }

    field_0x66e = field_0x66d;
    return dungeon_no;
}

/* 800D0580-800D05D4       .text MapNoSet__7daAgb_cFUcUcUc */
void daAgb_c::MapNoSet(u8 param_0, u8 param_1, u8 param_2) {
    field_0x66c = param_0;
    field_0x66d = param_1;
    field_0x67e = param_2 != 0;
    field_0x670 = 1;

    mFlags.field_0xb_3 = DungeonNoGet();
}

/* 800D05D4-800D05F0       .text onFree__7daAgb_cFv */
void daAgb_c::onFree() {
    field_0x671 = 1;
    field_0x650 = -1;
    field_0x677 = 0;
}

/* 800D05F0-800D0608       .text onHold__7daAgb_cFv */
void daAgb_c::onHold() {
    field_0x674 = 1;
    mBrk.setPlaySpeed(6.0f);
}

/* 800D0608-800D0620       .text offHold__7daAgb_cFv */
void daAgb_c::offHold() {
    field_0x674 = 0;
    mBrk.setPlaySpeed(1.0f);
}

/* 800D0620-800D070C       .text resetCursor__7daAgb_cFb */
void daAgb_c::resetCursor(bool param_0) {
    fopAc_ac_c* player_p = dComIfGp_getPlayer(0);
    field_0x671 = 0;
    field_0x677 = 0;
    field_0x650 = -1;

    if (fopAcM_GetName(player_p) != PROC_NPC_KAM) {
        current.pos = player_p->current.pos;
        orig.pos = player_p->current.pos;
    } else {
        current.pos = daPy_getPlayerLinkActorClass()->current.pos;
        orig.pos = daPy_getPlayerLinkActorClass()->current.pos;
    }

    field_0x628 = 2.5f;
    shape_angle.x = 0;
    shape_angle.y = 0;
    shape_angle.z = 0;

    if (param_0) {
        if (field_0x66b == 14) {
            field_0x65c = 0;
        }

        field_0x675 = 0;
        field_0x676 = 0;
    }

    field_0x674 = 0;
    mBrk.setPlaySpeed(1.0f);
}

/* 800D070C-800D0734       .text FlashCheck__7daAgb_cFv */
bool daAgb_c::FlashCheck() {
    if (field_0x671 != 0 || field_0x677 == 1) {
        return true;
    }

    return false;
}

/* 800D0734-800D0978       .text FlagsRecv__7daAgb_cFv */
// NONMATCHING - a lot of issues, not really sure what's going on here
void daAgb_c::FlagsRecv() {
    int portNo = mDoGaC_getPortNo();
    interface_of_controller_pad* pad_p = &g_mDoCPd_cpadInfo[portNo];
    u32 temp_r3 = BigLittleChange(mGbaFlg.field_0x0);

    u32 temp_r0 = temp_r3 >> 0x10U;
    pad_p->mButtonHold0 = (u8)((pad_p->mButtonHold0 & ~0x10) | ((temp_r3 >> 0x12) & 0x10));
    pad_p->mButtonHold0 = (u8)((pad_p->mButtonHold0 & ~0x20) | ((temp_r3 >> 0x12) & 0x20));
    pad_p->mButtonHold0 = (u8)((pad_p->mButtonHold0 & ~0x80) | ((temp_r3 >> 0xE) & 0x80));
    pad_p->mButtonHold0 = (u8)((pad_p->mButtonHold0 & ~0x40) | ((temp_r3 >> 0xE) & 0x40));
    pad_p->mButtonHold0 = (u8)((pad_p->mButtonHold0 & ~1) | ((temp_r3 >> 0x10) & 1));
    pad_p->mButtonHold1 = (u8)((pad_p->mButtonHold1 & ~0x80) | ((temp_r3 >> 0xA) & 0x80));
    pad_p->mButtonHold0 = (u8)((pad_p->mButtonHold0 & ~4) | ((temp_r3 >> 0x16) & 4));
    pad_p->mButtonHold0 = (u8)((pad_p->mButtonHold0 & ~2) | ((temp_r3 >> 0x18) & 2));
    pad_p->mButtonHold1 =
        (u8)((pad_p->mButtonHold1 & ~0x10) | ((((temp_r3 >> 0x13) & 1) << 4) & 0x10));

    u32 temp_r5 = temp_r0 & (temp_r0 ^ field_0x65a);
    pad_p->mButtonTrig0 = (u8)((pad_p->mButtonTrig0 & ~0x10) | ((temp_r5 >> 2) & 0x10));
    pad_p->mButtonTrig0 = (u8)((pad_p->mButtonTrig0 & ~0x20) | ((temp_r5 >> 2) & 0x20));
    pad_p->mButtonTrig0 = (u8)((pad_p->mButtonTrig0 & ~0x80) | ((temp_r5 << 2) & 0x80));
    pad_p->mButtonTrig0 = (u8)((pad_p->mButtonTrig0 & ~0x40) | ((temp_r5 << 2) & 0x40));
    pad_p->mButtonTrig0 = (u8)((pad_p->mButtonTrig0 & ~1) | (temp_r5 & 1));
    pad_p->mButtonTrig1 = (u8)((pad_p->mButtonTrig1 & ~0x80) | ((temp_r5 << 6) & 0x80));
    pad_p->mButtonTrig0 = (u8)((pad_p->mButtonTrig0 & ~4) | ((temp_r5 >> 6) & 4));
    pad_p->mButtonTrig0 = (u8)((pad_p->mButtonTrig0 & ~2) | ((temp_r5 >> 8) & 2));
    pad_p->mButtonTrig1 = (u8)((pad_p->mButtonTrig1 & ~0x10) | ((temp_r5 << 1) & 0x10));

    g_mDoCPd_cpadInfo[portNo].mGamepadErrorFlags = 0;

    field_0x65a = temp_r0;
    field_0x673 = mGbaFlg.field_0x3 != 0;
    field_0x630 = BigLittleChange(mGbaFlg.field_0x4) >> 0x10;
    field_0x632 = BigLittleChange(mGbaFlg.field_0x6) >> 0x10;
    field_0x67a = (mGbaFlg.field_0x2 >> 2);

    if (!dComIfGs_isEventBit(0x1708) && ((mGbaFlg.field_0x2 >> 3) & 1)) {
        dComIfGs_onEventBit(0x1708);
    }

    if (!dComIfGs_isEventBit(0x1A10) && ((mGbaFlg.field_0x2 >> 4) & 1)) {
        dComIfGs_onEventBit(0x1A10);
    }

    if (!dComIfGs_isEventBit(0x1A08) && ((mGbaFlg.field_0x2 >> 5) & 1)) {
        dComIfGs_onEventBit(0x1A08);
    }
}

/* 800D0978-800D0A54       .text SwitchOn__7daAgb_cFv */
void daAgb_c::SwitchOn() {
    if (mSwitch.field_0x1 == (u8)dStage_stagInfo_GetSaveTbl(dComIfGp_getStageStagInfo())) {
        u8 var_r31 = mSwitch.field_0x3 - 1;

        if (mSwitch.field_0x0 != 0xFF) {
            dComIfGs_revSwitch(mSwitch.field_0x0, mSwitch.field_0x2);
        }

        if (var_r31 != 9) {
            u8 sw = mSwitch.field_0x4;
            if (sw != 0xFF) {
                if (var_r31 <= 1 || var_r31 == 8) {
                    dComIfGs_onSwitch(sw, mSwitch.field_0x2);
                } else {
                    dComIfGs_revSwitch(sw, mSwitch.field_0x2);
                }
            }
        }
    }

    g_mDoGaC_gbaCom.mDoGaC_DataStatusReset(8);
}

/* 800D0A54-800D1188       .text GbaItemUse__7daAgb_cFv */
// NONMATCHING - mostly done, some regswaps
void daAgb_c::GbaItemUse() {
    u32 temp_r29 = mItem.field_0x0;
    u32 var_r28 = 0;

    u32 temp_r0 = temp_r29 - 3;
    if (temp_r0 == 0 || temp_r0 == 1 || temp_r0 == 2 || temp_r29 == 0x11 || temp_r29 == 0x12) {
        s32 roomNo = dComIfGp_roomControl_getStayNo();
        dStage_FileList_dt_c* fili_p =
            dComIfGp_roomControl_getStatusRoomDt(roomNo)->getFileListInfo();

        if (fili_p != NULL && fili_p->mParam & 4) {
            if (field_0x67c != 0) {
                mEffect = BigLittleChange((field_0x660 << 0x10) | 0x300);
                return;
            } else if (temp_r29 == 5) {
                f32 temp_f1 = cM_rndF(100.0f);

                if (temp_f1 < 10.0f) {
                    var_r28 = 0x13;
                } else if (temp_f1 < 40.0) {
                    var_r28 = 0xA;
                } else if (temp_f1 < 70.0) {
                    var_r28 = 0xD;
                } else if (dComIfGs_isEventBit(0x2E08)) {
                    var_r28 = 0xC;
                } else {
                    var_r28 = 0xD;
                }

                if ((var_r28 == 0xC || var_r28 == 0xD) &&
                    (daPy_getPlayerLinkActorClass()->checkEquipDragonShield()))
                {
                    var_r28 = 0xA;
                }
            }
        } else {
            mEffect = 0x20000;
            return;
        }
    }

    if (dComIfGs_getRupee() < mItem.field_0x1) {
        mEffect = 0x10000;
        return;
    }

    switch (temp_r29) {
    case 16:
        if (daPy_getPlayerLinkActorClass() != dComIfGp_getPlayer(0) ||
            dComIfGp_checkPlayerStatus0(0, 0x8000000) ||
            (daPy_getPlayerLinkActorClass()->checkPlayerFly() &&
             !dComIfGp_checkPlayerStatus0(0, 0x100000) && !dComIfGp_checkPlayerStatus0(0, 0x10000)))
        {
            mEffect = BigLittleChange(0x1F0300);
            return;
        } else if (field_0x67d != 0) {
            mEffect = BigLittleChange((field_0x662 << 0x10) | 0x300);
            return;
        }
        field_0x67f = 1;
        break;
    case 2:
        if (field_0x67b != 0) {
            mEffect = BigLittleChange((field_0x65e << 0x10) | 0x300);
            return;
        }

        if (daPy_getPlayerLinkActorClass() != dComIfGp_getPlayer(0) &&
            fopAcM_searchPlayerDistanceXZ(this) < 232.0f)
        {
            mEffect = 0;
            return;
        }

        if ((int)field_0x671 != 0 || (int)field_0x677 == 1) {
            if ((int)field_0x671 == 0 && dComIfGs_getGbaRupeeCount() < 24 &&
                fopAcM_IsExecuting(field_0x650))
            {
                fopAc_ac_c* actor_p = fopAcM_SearchByID(field_0x650);

                if (cM_rndF(5.0f) < 4.0) {
                    field_0x640 = 3;
                } else {
                    field_0x640 = 4;
                }

                field_0x634 = actor_p->current.pos;
                dComIfGs_incGbaRupeeCount();
                temp_r29 = 15;
            }

            fopAcM_create(0x128, daBomb_c::prm_make(daBomb_c::STATE_8_e, false, false),
                          &current.pos, -1, NULL, NULL, -1, NULL);
            field_0x65c = 0x78;
        } else {
            temp_r29 = 0xe;
            onFree();
            field_0x65c = 0x10e;
            mBrk.setPlaySpeed(6.0f);
        }
        break;
    case 0x15:
        resetCursor(false);
        fopAcM_create(0x128, daBomb_c::prm_make(daBomb_c::STATE_8_e, false, false), &current.pos,
                      -1, NULL, NULL, -1, NULL);
        field_0x65c = 0x78;
        break;
    case 0x11:
        mEffect = BigLittleChange(temp_r29);
        return;
    case 3:
        daPy_lk_c* temp_r3 = daPy_getPlayerLinkActorClass();
        temp_r3->onNoResetFlg0(daPy_py_c::daPyFlg0_UNK1000);
        temp_r3->field_0x354c = 0x96;
        resetCursor(false);
        field_0x65c = 0x96;
        mBrk.setPlaySpeed(6.0f);
        break;
    case 0x12:
        if (daPy_getPlayerLinkActorClass()->checkEquipDragonShield()) {
            mEffect = 0;
            return;
        } else {
            mEffect = BigLittleChange(temp_r29);
            return;
        }
        break;
    case 4:
        if (daPy_getPlayerLinkActorClass()->checkEquipDragonShield()) {
            mEffect = 0;
            return;
        } else {
            daPy_getPlayerLinkActorClass()->field_0x354e = 300;
            resetCursor(false);
            field_0x65c = 300;
            mBrk.setPlaySpeed(6.0f);
        }
        break;
    case 12:
        if (field_0x67c != 0) {
            mEffect = BigLittleChange((field_0x660 << 0x10) | 0x300);
            return;
        } else {
            daPy_lk_c* temp_r4 = daPy_getPlayerLinkActorClass();
            temp_r4->onNoResetFlg0(daPy_py_c::daPyFlg0_UNK1000);
            temp_r4->field_0x354c = 300;
            if (!(daPy_getPlayerLinkActorClass()->checkEquipDragonShield())) {
                temp_r4->field_0x354e = 300;
            }

            resetCursor(false);
            field_0x65c = 300;
            mBrk.setPlaySpeed(6.0f);
        }
        break;
    case 13:
        if (field_0x67c != 0) {
            mEffect = BigLittleChange((field_0x660 << 0x10) | 0x300);
            return;
        } else {
            if ((daPy_getPlayerLinkActorClass()->checkEquipDragonShield())) {
                mEffect = 0;
                return;
            }

            daPy_getPlayerLinkActorClass()->field_0x354e = 600;

            resetCursor(false);
            field_0x65c = 600;
            mBrk.setPlaySpeed(6.0f);
        }
        break;
    case 5:
        temp_r29 |= (var_r28 << 8);
        resetCursor(false);
        break;
    case 0x13:
        resetCursor(false);
        field_0x65c = 30;
        break;
    case 7:
        if (dComIfGs_checkGetItem(ESA_BAG)) {
            if (dComIfGs_checkBaitItemEmpty()) {
                temp_r29 |= 0x1000000;
            }

            if (dComIfGs_checkGetItem(BOMB_BAG) && dComIfGs_getBombNum() < dComIfGs_getBombMax()) {
                temp_r29 |= 0x10000;
            }

            if (dComIfGs_getItem(12) != NO_ITEM && dComIfGs_getArrowNum() < dComIfGs_getArrowMax())
            {
                temp_r29 |= 0x100;
            }
        }
        break;
    case 0x14:
        resetCursor(false);
        break;
    case 8:
        dComIfGp_setItemLifeCount(12.0f);
        resetCursor(false);
        field_0x65c = 60;
        break;
    case 9:
        dComIfGp_setItemMagicCount(8);
        resetCursor(false);
        field_0x65c = 60;
        break;
    case 10:
        dComIfGp_setItemLifeCount(dComIfGs_getMaxLife());
        dComIfGp_setItemMagicCount(dComIfGs_getMaxMagic());
        resetCursor(false);
        field_0x65c = 60;
        break;
    default:
        mEffect = 0;
        return;
    }

    field_0x672 = 0;
    dComIfGp_setItemRupeeCount(-mItem.field_0x1);
    mEffect = BigLittleChange(temp_r29);
    field_0x66b = temp_r29;
}

/* 800D1188-800D12E4       .text Shopping__7daAgb_cFv */
void daAgb_c::Shopping() {
    /* Nonmatching */
}

/* 800D12E4-800D1A3C       .text FlagsSend__7daAgb_cFUl */
void daAgb_c::FlagsSend(u32) {
    /* Nonmatching */
}

/* 800D1A3C-800D25D8       .text CursorMove__7daAgb_cFP10fopAc_ac_cUl */
void daAgb_c::CursorMove(fopAc_ac_c*, u32) {
    /* Nonmatching */
}

/* 800D272C-800D303C       .text modeMove__7daAgb_cFv */
void daAgb_c::modeMove() {
    /* Nonmatching */
}

/* 800D303C-800D30D4       .text modeDelete__7daAgb_cFv */
void daAgb_c::modeDelete() {
    if (field_0x664 == 0 && g_mDoGaC_gbaCom.mDoGaC_GbaLink() &&
        g_mDoGaC_gbaCom.mDoGaC_SendStatusCheck(1))
    {
        mPlayerName = 0x1000000;
        g_mDoGaC_gbaCom.mDoGaC_SendDataSet((u32*)&mPlayerName, 4, 1, 0);
        field_0x664++;
    }
}

void daAgb_c::modeProcCall() {
    typedef void (daAgb_c::*modeProc)();
    static modeProc mode_proc[] = {
        &daAgb_c::modeMove,
        &daAgb_c::modeLookAttention,
        &daAgb_c::modeLoad,
        &daAgb_c::modeDelete,
    };

    (this->*mode_proc[mMode])();
}

/* 800D30D4-800D36F4       .text daAgb_Execute__FP7daAgb_c */
// NONMATCHING - regswap
int daAgb_Execute(daAgb_c* i_this) {
    daPy_lk_c* temp_r29 = (daPy_lk_c*)dComIfGp_getPlayer(0);
    i_this->field_0x679 = 0;

    if (g_mDoGaC_gbaCom.mDoGaC_GbaLink() && g_mDoGaC_gbaCom.mDoGaC_RecvStatusCheck(4)) {
        i_this->FlagsRecv();
        g_mDoGaC_gbaCom.mDoGaC_DataStatusReset(4);
    } else {
        g_mDoCPd_cpadInfo[mDoGaC_getPortNo()].mGamepadErrorFlags = 1;
    }

    BOOL var_r27 = dComIfGp_event_runCheck() != 0;
    var_r27 |= dMenu_flag();

    u32 st_type = dStage_stagInfo_GetSTType(dComIfGp_getStageStagInfo());

    if (g_mDoGaC_gbaCom.mDoGaC_GbaLink()) {
        if (g_mDoGaC_gbaCom.mDoGaC_RecvStatusCheck(8)) {
            i_this->SwitchOn();
        }

        if (g_mDoGaC_gbaCom.mDoGaC_SendStatusCheck(9)) {
            i_this->FlagsSend(st_type);
        }

        i_this->field_0x680 = 1;
    } else if (i_this->field_0x680) {
        i_this->field_0x680 = 0;
        i_this->resetCursor(true);
        i_this->field_0x672 = 0;

        if (i_this->field_0x65c != 0) {
            if (i_this->field_0x66b == 3 || i_this->field_0x66b == 12) {
                daPy_lk_c* player_p = daPy_getPlayerLinkActorClass();
                player_p->onNoResetFlg0(daPy_py_c::daPyFlg0_UNK1000);
                player_p->field_0x354c = 10;
            } else if (i_this->field_0x66b == 4 || i_this->field_0x66b == 13 ||
                       i_this->field_0x66b == 12)
            {
                daPy_lk_c* player_p = daPy_getPlayerLinkActorClass();
                player_p->field_0x354e = 10;
            }

            i_this->field_0x65c = 0;
        }

        i_this->field_0x66b = 0;
        i_this->field_0x630 = 0;
        i_this->field_0x632 = 0;
        i_this->field_0x684.end();
    }

    i_this->modeProcCall();

    if (g_mDoGaC_gbaCom.mDoGaC_GbaLink()) {
        if ((int)i_this->field_0x671 != 0) {
            if (i_this->current.pos.x != i_this->next.pos.x ||
                i_this->current.pos.z != i_this->next.pos.z)
            {
                daAgb_c::mFlags.field_0x5_3 = 1;
            } else {
                daAgb_c::mFlags.field_0x5_3 = 0;
            }
        } else {
            daPy_lk_c* player_p2 = daPy_getPlayerLinkActorClass();
            if ((dComIfGp_getPlayer(0) == player_p2 && !temp_r29->checkPlayerFly()) ||
                ((fopAcM_GetName(temp_r29) == PROC_NPC_MD && !daNpc_Md_c::m_flying) ||
                 (fopAcM_GetName(temp_r29) == PROC_NPC_CB1 && !daNpc_Cb1_c::m_flying) ||
                 fopAcM_GetName(temp_r29) == PROC_NPC_OS))
            {
                f32 speedF = fabs(temp_r29->speedF);

                if (speedF <= 0.0f) {
                    daAgb_c::mFlags.field_0x5_3 = 0;
                } else if (speedF < 5.0f) {
                    daAgb_c::mFlags.field_0x5_3 = 1;
                } else if (speedF < 10.0f) {
                    daAgb_c::mFlags.field_0x5_3 = 2;
                } else if (speedF < 15.0f) {
                    daAgb_c::mFlags.field_0x5_3 = 3;
                } else {
                    daAgb_c::mFlags.field_0x5_3 = 4;
                }
            } else {
                daAgb_c::mFlags.field_0x5_3 = 0;
            }
        }

        if ((int)i_this->field_0x674 != 0 && var_r27 == 0 && i_this->mMode != 1) {
            if (i_this->field_0x675 != 0) {
                if (i_this->field_0x676 != 0) {
                    i_this->shape_angle.z += 0x1000;
                } else {
                    i_this->shape_angle.z = fopAcM_searchPlayerAngleY(i_this);
                }
            } else {
                i_this->shape_angle.z += 0x200;
            }
        }

        mDoMtx_stack_c::transS(i_this->current.pos.x, i_this->current.pos.y + i_this->field_0x628,
                               i_this->current.pos.z);
        mDoMtx_stack_c::YrotM(i_this->shape_angle.y);
        mDoMtx_stack_c::XrotM(i_this->shape_angle.x);
        mDoMtx_stack_c::ZrotM(i_this->shape_angle.z);
        i_this->mpModel->setBaseTRMtx(mDoMtx_stack_c::get());

        if (i_this->mMode == 1) {
            i_this->mBrk.setFrame(15.0f);
        } else if (i_this->field_0x65c != 0 &&
                   (i_this->field_0x66b == 4 || i_this->field_0x66b == 13 ||
                    i_this->field_0x66b == 12 || i_this->field_0x66b == 3))
        {
            if (i_this->field_0x65c > 60) {
                i_this->mBrk.setFrame(19.0f);
            } else {
                i_this->mBrk.play();
            }
        } else if ((((int)i_this->field_0x672 != 0 || i_this->field_0x676 != 0) &&
                    ((int)i_this->field_0x671 != 0 || (int)i_this->field_0x677 == 1)) ||
                   (i_this->field_0x66b == 14 && i_this->field_0x65c > 120))
        {
            i_this->mBrk.play();
        } else {
            i_this->mBrk.setFrame(0.0f);
        }
    }

    return 1;
}

/* 800D36F4-800D38EC       .text daAgb_Draw__FP7daAgb_c */
int daAgb_Draw(daAgb_c* i_this) {
    u8 var_r6 = 1;

    if (g_mDoGaC_gbaCom.mDoGaC_GbaLink()) {
        if (i_this->field_0x66f != 0 && !(daAgb_c::mFlags.field_0xa & 1) &&
            (!dComIfGp_event_runCheck() ||
             dComIfGp_evmng_startCheck("DEFAULT_AGB_LOOK_ATTENTION") ||
             i_this->mMode == 2) &&
            (i_this->field_0x65c == 0 || i_this->mMode == 1 || i_this->field_0x66b == 0x10 ||
             i_this->field_0x66b == 3 || i_this->field_0x66b == 12 || i_this->field_0x66b == 4 ||
             i_this->field_0x66b == 13 || (i_this->field_0x66b == 14 && i_this->field_0x65c > 120)))
        {
            i_this->mBrk.getBrkAnm()->setFrame(i_this->mBrk.getFrame());

            J3DModelData* modelData = i_this->mpModel->getModelData();
            for (u16 i = 0; i < modelData->getMaterialNum(); i++) {
                J3DMaterial* mat_p = modelData->getMaterialNodePointer(i);
                mat_p->setTevColor(1, &l_HIO.field_0x04[0]);
                mat_p->setTevColor(2, &l_HIO.field_0x04[1]);
            }

            mDoExt_modelUpdateDL(i_this->mpModel);

            if (i_this->field_0x679 != 0 &&
                i_this->current.pos.y - i_this->mCrrPos.field_0x05c > 2.5f)
            {
                dComIfGd_setSimpleShadow2(&i_this->current.pos, i_this->mCrrPos.field_0x05c, 50.0f,
                                          i_this->mCrrPos.mGndChk, 0, 1.0f, &i_this->mTexObj);
            }

            var_r6 = 0;
        }
    }

    dMap_c::drawPointSingle(3, i_this->current.pos.x, i_this->current.pos.y, i_this->current.pos.z,
                            i_this->current.roomNo, -0x8000, var_r6, 0, 0);
    return 1;
}

/* 800D38EC-800D38F0       .text setTevColor__11J3DTevBlockFUlPC13J3DGXColorS10 */
void J3DTevBlock::setTevColor(u32, const J3DGXColorS10*) {
    /* Nonmatching */
}

/* 800D38F0-800D38F8       .text daAgb_IsDelete__FP7daAgb_c */
int daAgb_IsDelete(daAgb_c* i_this) {
    return 1;
}

/* 800D38F8-800D394C       .text daAgb_Delete__FP7daAgb_c */
int daAgb_Delete(daAgb_c* i_this) {
    dComIfG_resDelete(&i_this->mPhase, "Agb");
    i_this->field_0x684.end();
    return 1;
}

/* 800D394C-800D396C       .text createHeap_CB__FP10fopAc_ac_c */
int createHeap_CB(fopAc_ac_c* i_this) {
    return static_cast<daAgb_c*>(i_this)->createHeap();
}

/* 800D396C-800D3B58       .text createHeap__7daAgb_cFv */
int daAgb_c::createHeap() {
    J3DModelData* modelData = (J3DModelData*)dComIfG_getObjectRes("Agb", 4);
    JUT_ASSERT(3277, modelData != 0);

    mpModel = mDoExt_J3DModel__create(modelData, 0x80000, 0x11000002);
    if (mpModel == NULL) {
        return 0;
    }

    J3DAnmTevRegKey* pbrk = (J3DAnmTevRegKey*)dComIfG_getObjectRes("Agb", 7);
    if (!mBrk.init(modelData, pbrk, TRUE, J3DFrameCtrl::LOOP_REPEAT_e, 1.0f, 0, -1, false, 1)) {
        return 0;
    }

    ResTIMG* img_p = modelData->getTexture()->getResTIMG(1);
    GXInitTexObj(&mTexObj, (u8*)img_p + img_p->imageOffset, img_p->width, img_p->height,
                 (GXTexFmt)img_p->format, (GXTexWrapMode)img_p->wrapS, (GXTexWrapMode)img_p->wrapT,
                 (GXBool)(img_p->mipmapCount > 1));
    GXInitTexObjLOD(&mTexObj, (GXTexFilter)img_p->minFilter, (GXTexFilter)img_p->magFilter,
                    img_p->minLOD * 0.125f, img_p->maxLOD * 0.125f, img_p->LODBias * 0.01f,
                    img_p->biasClamp, img_p->doEdgeLOD, (GXAnisotropy)img_p->maxAnisotropy);

    return 1;
}

/* 800D3B58-800D3D2C       .text daAgb_Create__FP10fopAc_ac_c */
// NONMATCHING - dBgS_CrrPos::Set needs works
int daAgb_Create(fopAc_ac_c* i_this) {
    fopAcM_SetupActor(i_this, daAgb_c);
    daAgb_c* a_this = (daAgb_c*)i_this;

    int phase = dComIfG_resLoad(&a_this->mPhase, "Agb");
    if (phase == cPhs_COMPLEATE_e) {
        dComIfGp_setAgb(a_this);
        if (!fopAcM_entrySolidHeap(a_this, createHeap_CB, 0x500)) {
            return cPhs_ERROR_e;
        }

        // a_this->mCrrPos.Set(&a_this->current.pos, &a_this->next.pos, NULL, );
        a_this->mCrrPos.mpLine0 = &a_this->current.pos;
        a_this->mCrrPos.pm_pos = &a_this->next.pos;
        a_this->mCrrPos.field_0x058 = NULL;
        a_this->mCrrPos.SetActorPid(-1);
        a_this->mCrrPos.field_0x3c = 171.0f;
        a_this->mCrrPos.field_0x40 = 50.0f;

        a_this->mCrrPos.SetGndUpY(170.0f);
        a_this->mCrrPos.ClrNoRoof();
        a_this->mAcch.Set(&a_this->current.pos, &a_this->next.pos, a_this, 1, &a_this->mAcchCir,
                          NULL, NULL, NULL);
        a_this->mAcch.OnLineCheck();
        a_this->mAcch.SetGrndNone();
        a_this->mAcchCir.SetWall(171.01f, 40.0f);

        TestDataManager[4].field_0x0 = (u32)&daAgb_c::mGbaFlg;
        TestDataManager[8].field_0x0 = (u32)&daAgb_c::mSwitch;
        TestDataManager[6].field_0x0 = (u32)&daAgb_c::mItem;
        TestDataManager[12].field_0x0 = (u32)&daAgb_c::mShop;

        a_this->field_0x670 = 0;
        a_this->field_0x65c = 0;
        a_this->field_0x66b = 0;
        a_this->field_0x66f = g_mDoGaC_gbaCom.field_0x0;
        a_this->field_0x678 = g_mDoGaC_gbaCom.field_0x0 > 0;
        a_this->field_0x654 = 0;
        a_this->field_0x650 = -1;
        a_this->field_0x677 = 0;
        a_this->field_0x67b = 0;
        a_this->field_0x680 = 1;

        fopAcM_setStageLayer(a_this);
        a_this->mEvtInfo.setEventName("DEFAULT_AGB_USE");
    }

    return phase;
}

/* 800D3D2C-800D3DDC       .text __ct__7daAgb_cFv */
daAgb_c::daAgb_c() : field_0x684(0, 0) {}
