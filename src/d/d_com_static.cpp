//
// Generated by dtk
// Translation Unit: d_com_static.cpp
//

#include "dolphin/types.h"
#include "d/d_com_inf_game.h"
#include "d/actor/d_a_obj_pirateship.h"
#include "d/actor/d_a_agb.h"
#include "d/actor/d_a_agbsw0.h"
#include "d/actor/d_a_npc_os.h"
#include "d/actor/d_a_npc_md.h"
#include "d/actor/d_a_arrow.h"
#include "d/actor/d_a_ib.h"
#include "d/actor/d_a_obj_movebox.h"
#include "d/actor/d_a_tag_kb_item.h"
#include "d/actor/d_a_item.h"
#include "d/actor/d_a_tag_waterlevel.h"
#include "d/actor/d_a_title.h"
#include "d/d_procname.h"
#include "d/actor/d_a_npc_kamome.h"

static Vec dummy_3569;

// /* 8005662C-80056638       .text init__12daSteamTag_cFv */
// void daSteamTag_c::init() {
//     /* Nonmatching */
// }

/* 80056638-800566F0       .text getShipOffsetY__15daObjPirateshipFPsPsf */
f32 daObjPirateship::getShipOffsetY(s16* param_1, s16* param_2, f32 param_3) {
    if (*param_1 > 0x4000 || *param_1 < -0x4000) {
        cLib_addCalcAngleS2(param_2, 0x280, 0x10, 0x300);
    } else {
        cLib_addCalcAngleS2(param_2, 0x180, 0x10, 0x300);
    }
    *param_1 += *param_2;
    return param_3 * cM_ssin(*param_1);
}

f32 daTagWaterlevel::Act_c::M_now;
u32 daTagWaterlevel::Act_c::M_state;

daAgb_c::daAgb_Flags daAgb_c::mFlags;
u8 daAgbsw0_c::mFigureDispose;
u8 daAgbsw0_c::mFigureBeat;

/* 800566F0-80056728       .text incTclDispose__10daAgbsw0_cFv */
void daAgbsw0_c::incTclDispose() {
    daAgb_c* agb = dComIfGp_getAgb();
    if (!agb) {
        return;
    }
    if (!agb->isActive()) {
        return;
    }
    if (mFigureDispose >= 2) {
        return;
    }
    mFigureDispose++;
}

/* 80056728-80056760       .text incTclBeat__10daAgbsw0_cFv */
void daAgbsw0_c::incTclBeat() {
    daAgb_c* agb = dComIfGp_getAgb();
    if (!agb) {
        return;
    }
    if (!agb->isActive()) {
        return;
    }
    if (mFigureBeat >= 6) {
        return;
    }
    mFigureBeat++;
}

// /* 80056760-80056790       .text init_room__11daSalvage_cFSc */
// void daSalvage_c::init_room(signed char) {
//     /* Nonmatching */
// }

// /* 80056790-800567F8       .text renew_light_angle__Q210daObjLight5Act_cFv */
// void daObjLight::Act_c::renew_light_angle() {
//     /* Nonmatching */
// }

// /* 800567F8-80056824       .text get_light_angle__Q210daObjLight5Act_cFv */
// void daObjLight::Act_c::get_light_angle() {
//     /* Nonmatching */
// }

// /* 80056824-8005682C       .text get_light_dif_angle__Q210daObjLight5Act_cFv */
// void daObjLight::Act_c::get_light_dif_angle() {
//     /* Nonmatching */
// }

// /* 8005682C-80056860       .text set_light_dif_angle_LOD__Q210daObjLight5Act_cFs */
// void daObjLight::Act_c::set_light_dif_angle_LOD(short) {
//     /* Nonmatching */
// }

// /* 80056860-800568A8       .text set_light_dif_angle_FRRS__Q210daObjLight5Act_cFs */
// void daObjLight::Act_c::set_light_dif_angle_FRRS(short) {
//     /* Nonmatching */
// }

// /* 800568A8-800568B0       .text getMaxDaiza__7daDai_cFv */
// void daDai_c::getMaxDaiza() {
//     /* Nonmatching */
// }

// /* 800568B0-800568B8       .text getDaizaSetItemNum__7daDai_cFv */
// void daDai_c::getDaizaSetItemNum() {
//     /* Nonmatching */
// }

bool daNpc_Os_c::m_playerRoom[3] = { false, false, false };
s8 daNpc_Os_c::m_cattleRoomNo = -1;
dPa_smokeEcallBack daNpc_Os_c::m_smoke(0, 1, 1, 1);
dKy_tevstr_c daNpc_Os_c::m_smoke_tevstr;

bool daNpc_Md_c::m_flying;
bool daNpc_Md_c::m_mirror;
bool daNpc_Md_c::m_seaTalk;
s16 daNpc_Md_c::m_flyingTimer;
bool daNpc_Md_c::m_playerRoom;

/* 800568B8-800568C0       .text getMaxFlyingTimer__10daNpc_Md_cFv */
s16 daNpc_Md_c::getMaxFlyingTimer() {
    return 15*30;
}

u8 daArrow_c::m_keep_type;

/* 800568C0-800568C8       .text getKeepType__9daArrow_cFv */
u8 daArrow_c::getKeepType() {
    return m_keep_type;
}

/* 800568C8-800568D0       .text setKeepType__9daArrow_cFUc */
void daArrow_c::setKeepType(u8 type) {
    m_keep_type = type;
}

u32 daIball_c::m_ib_actor[5];

/* 800568D0-800568F8       .text init__9daIball_cFv */
void daIball_c::init() {
    for (int i = 0; i < ARRAY_SIZE(m_ib_actor); i++) {
        m_ib_actor[i] = -1;
    }
}

/* 800568F8-80056944       .text regist__9daIball_cFP10fopAc_ac_c */
void daIball_c::regist(fopAc_ac_c* i_actor) {
    for (int i = 0; i < ARRAY_SIZE(m_ib_actor); i++) {
        if (m_ib_actor[i] == -1) {
            m_ib_actor[i] = fopAcM_GetID(i_actor);
            break;
        }
    }
}

/* 80056944-80056990       .text remove__9daIball_cFP10fopAc_ac_c */
void daIball_c::remove(fopAc_ac_c* i_actor) {
    for (int i = 0; i < ARRAY_SIZE(m_ib_actor); i++) {
        if (m_ib_actor[i] == fopAcM_GetID(i_actor)) {
            m_ib_actor[i] = -1;
            break;
        }
    }
}

/* 80056990-80056A18       .text remove_old__9daIball_cFv */
void daIball_c::remove_old() {
    u32 iball_id = -1;
    for (int i = 0; i < ARRAY_SIZE(m_ib_actor); i++) {
        if (m_ib_actor[i] == -1) {
            return;
        }
        if (m_ib_actor[i] < iball_id) {
            iball_id = m_ib_actor[i];
        }
    }
    fopAc_ac_c* iball = fopAcM_SearchByID(iball_id);
    if (iball) {
        static_cast<daIball_c*>(iball)->dead();
        remove(iball);
    }
}

// /* 80056A18-80056AD0       .text getCreateCount__13daObj_Roten_cFv */
// void daObj_Roten_c::getCreateCount() {
//     /* Nonmatching */
// }

const s16 daObjMovebox::Act_c::M_dir_base[4] = {
    0x0000,
    0x4000,
    0x8000,
    0xC000,
};

/* 80056AD0-80056AFC       .text kb_dig__13daTagKbItem_cFP10fopAc_ac_c */
void daTagKbItem_c::kb_dig(fopAc_ac_c* i_actor) {
    field_0x299 = 1;
    mpActor = i_actor;
    dig_main();
}

/* 80056AFC-80056CC0       .text dig_main__13daTagKbItem_cFv */
void daTagKbItem_c::dig_main() {
    if (fopAcM_isSwitch(this, field_0x2a4)) {
        return;
    }
    if (field_0x299 == 0) {
        return;
    }
    if (field_0x298 != 0) {
        return;
    }
    
    cXyz scale = cXyz::Zero;
    csXyz angle = csXyz::Zero;
    bool r30 = false;
    if (!fopAcM_IsActor(mpActor)) {
        return;
    }
    if (fopAcM_GetName(mpActor) != PROC_KB) {
        // Not a pig.
        return;
    }
    if (field_0x2a0 != 0xFF) {
        angle.y = cM_rndF((f32)0x7FFE);
        s8 roomNo = current.roomNo;
        f32 speedY = cM_rndFX(5.0f) + 60.0f;
        f32 speedF = cM_rndF(5.0f);
        daItem_c* item = (daItem_c*)fopAcM_fastCreateItem(
            &mpActor->current.pos, field_0x2a0, roomNo, &angle,
            &scale, speedF, speedY, -6.0f, field_0x29c
        );
        if (item) {
            fopAcM_OnStatus(item, fopAcStts_UNK4000_e);
        }
        if (field_0x2a4 != 0xFF) {
            fopAcM_onSwitch(this, field_0x2a4);
        } else {
            fopAcM_delete(this);
        }
        r30 = true;
    }
    
    if (field_0x2a1 != 0xFF) {
        mpActor->orig.angle.z = field_0x2a1;
        fopAcM_onSwitch(this, field_0x2a4);
        fopAcM_delete(this);
        r30 = true;
    }
    
    if (r30) {
        field_0x298 = r30;
    }
    field_0x299 = 0;
}

bool daTitle_proc_c::daTitle_Kirakira_Sound_flag[] = { false };

/* 80056CC0-80056CCC       .text daTitle_Kirakira_Sound_flag_on__14daTitle_proc_cFv */
void daTitle_proc_c::daTitle_Kirakira_Sound_flag_on() {
    daTitle_Kirakira_Sound_flag[0] = true;
}

// /* 80056CCC-80056DE0       .text daiItemNodeCallBack__13daStandItem_cFP7J3DNodei */
// void daStandItem_c::daiItemNodeCallBack(J3DNode*, int) {
//     /* Nonmatching */
// }

bool daNpc_kam_c::m_hyoi_kamome;
