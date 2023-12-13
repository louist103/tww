//
// Generated by dtk
// Translation Unit: d_a_bk.cpp
//

#include "d/actor/d_a_bk.h"
#include "f_op/f_op_actor_mng.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "d/d_procname.h"
#include "d/d_com_inf_game.h"
#include "d/actor/d_a_obj_search.h"
#include "d/actor/d_a_item.h"
#include "d/d_item_data.h"
#include "d/actor/d_a_boko.h"
#include "d/d_bg_s_lin_chk.h"
#include "m_Do/m_Do_mtx.h"
#include "d/actor/d_a_player.h"

static bkHIO_c l_bkHIO;

enum BK_RES_FILE_ID { // IDs and indexes are synced
    /* BAS */
    BK_BAS_BK_AOMUKE=0x8,
    BK_BAS_BK_ATTACK1=0x9,
    BK_BAS_BK_ATTACK2=0xA,
    BK_BAS_BK_ATTACK3=0xB,
    BK_BAS_BK_BOKKURI=0xC,
    BK_BAS_BK_CATCH=0xD,
    BK_BAS_BK_HAKKEN=0xE,
    BK_BAS_BK_IATTACK1=0xF,
    BK_BAS_BK_JATTACK2=0x10,
    BK_BAS_BK_JATTACK3=0x11,
    BK_BAS_BK_JUMP1=0x12,
    BK_BAS_BK_JUMP2=0x13,
    BK_BAS_BK_KERI1=0x14,
    BK_BAS_BK_KERI2=0x15,
    BK_BAS_BK_KYORO1=0x16,
    BK_BAS_BK_KYORO2=0x17,
    BK_BAS_BK_NIGERU=0x18,
    BK_BAS_BK_NOBI=0x19,
    BK_BAS_BK_NOMWAIT=0x1A,
    BK_BAS_BK_OKIRUA=0x1B,
    BK_BAS_BK_OKIRUU=0x1C,
    BK_BAS_BK_OTISOU1=0x1D,
    BK_BAS_BK_OTISOU2=0x1E,
    BK_BAS_BK_RUN=0x1F,
    BK_BAS_BK_SLEEP=0x20,
    BK_BAS_BK_SUWARI=0x21,
    BK_BAS_BK_TUTUKU1=0x22,
    BK_BAS_BK_UTUBUSE=0x23,
    BK_BAS_BK_WAIT=0x24,
    BK_BAS_BK_WALK=0x25,
    BK_BAS_BK_WALK2=0x26,
    
    /* BCK */
    BK_BCK_BK_AOMUKE=0x29,
    BK_BCK_BK_ATTACK1=0x2A,
    BK_BCK_BK_ATTACK2=0x2B,
    BK_BCK_BK_ATTACK3=0x2C,
    BK_BCK_BK_BIKKURI=0x2D,
    BK_BCK_BK_BOUGYO1=0x2E,
    BK_BCK_BK_BOUGYO2=0x2F,
    BK_BCK_BK_CATCH=0x30,
    BK_BCK_BK_HAKKEN=0x31,
    BK_BCK_BK_HAKOBI=0x32,
    BK_BCK_BK_HIDARIROT=0x33,
    BK_BCK_BK_JATTACK1=0x34,
    BK_BCK_BK_JATTACK2=0x35,
    BK_BCK_BK_JATTACK3=0x36,
    BK_BCK_BK_JUMP1=0x37,
    BK_BCK_BK_JUMP2=0x38,
    BK_BCK_BK_KERI1=0x39,
    BK_BCK_BK_KERI2=0x3A,
    BK_BCK_BK_KIME=0x3B,
    BK_BCK_BK_KOUKA=0x3C,
    BK_BCK_BK_KYORO1=0x3D,
    BK_BCK_BK_KYORO2=0x3E,
    BK_BCK_BK_MIGIROT=0x3F,
    BK_BCK_BK_NIGERU=0x40,
    BK_BCK_BK_NOBI=0x41,
    BK_BCK_BK_NOMWAIT=0x42,
    BK_BCK_BK_NOZOKU=0x43,
    BK_BCK_BK_OKIRUA=0x44,
    BK_BCK_BK_OKIRUU=0x45,
    BK_BCK_BK_OTISOU1=0x46,
    BK_BCK_BK_OTISOU2=0x47,
    BK_BCK_BK_RUN=0x48,
    BK_BCK_BK_SLEEP=0x49,
    BK_BCK_BK_SUWARI=0x4A,
    BK_BCK_BK_TATAKU=0x4B,
    BK_BCK_BK_TUTUKU1=0x4C,
    BK_BCK_BK_TUTUKU2=0x4D,
    BK_BCK_BK_TUTUKU3=0x4E,
    BK_BCK_BK_TYAKU=0x4F,
    BK_BCK_BK_UTUBUSE=0x50,
    BK_BCK_BK_WAIT=0x51,
    BK_BCK_BK_WALK=0x52,
    BK_BCK_BK_WALK2=0x53,
    
    /* BDLM */
    BK_BDL_BK=0x56,
    BK_BDL_BOUEN=0x57,
    
    /* BMD */
    BK_BMD_BK_KB=0x5A,
    BK_BMD_BK_TATE=0x5B,
    
    /* BMT */
    BK_BMT_BK_BOKO=0x5E,
    BK_BMT_BK_KEN=0x5F,
    BK_BMT_GREEN=0x60,
    BK_BMT_PINK=0x61,
    
    /* BTP */
    BK_BTP_TMABATAKI=0x64,
};

/* 000000EC-00000234       .text anm_init__FP8bk_classifUcfi */
static void anm_init(bk_class* i_this, int bckFileIdx, f32 morf, u8 loopMode, f32 speed, int soundFileIdx) {
    if (i_this->mDamageReaction.mState == 0x13 && bckFileIdx != BK_BCK_BK_OTISOU1 && bckFileIdx != BK_BCK_BK_OTISOU2) {
        return;
    }
    if (soundFileIdx >= 0) {
        void* soundAnm = dComIfG_getObjectRes("AM2", soundFileIdx);
        J3DAnmTransform* bckAnm = (J3DAnmTransform*)dComIfG_getObjectRes("AM2", bckFileIdx);
        i_this->mpMorf->setAnm(bckAnm, loopMode, morf, speed, 0.0f, -1.0f, soundAnm);
    } else {
        J3DAnmTransform* bckAnm = (J3DAnmTransform*)dComIfG_getObjectRes("AM2", bckFileIdx);
        i_this->mpMorf->setAnm(bckAnm, loopMode, morf, speed, 0.0f, -1.0f, NULL);
    }
}

/* 00000234-000005A8       .text yari_off_check__FP8bk_class */
static void yari_off_check(bk_class* i_this) {
    if (i_this->m0B34 == 0) {
        return;
    }
    
    daBoko_c* boko = (daBoko_c*)fopAcM_SearchByID(i_this->m1200);
    if (boko) {
        daPy_py_c* player = (daPy_py_c*)dComIfGp_getPlayer(0);
        fopAcM_cancelCarryNow(boko);
        
        if (i_this->m0B34 != 2) {
            boko->setRotAngleSpeed(cM_rndFX(2000.0f));
            s16 angleY = i_this->shape_angle.y + 0x8000 + (s16)cM_rndFX(8000.0f);
            f32 speedY = 20.0f + cM_rndF(20.0f);
            f32 speedForward = 20.0f + cM_rndF(10.0f);
            boko->moveStateInit(speedForward, speedY, angleY);
        }
        boko->current.angle.y = player->shape_angle.y;
        
        dBgS_LinChk linChk;
        linChk.Set(&i_this->mEyePos, &boko->current.pos, i_this);
        if (dComIfG_Bgsp()->LineCross(&linChk)) {
            MtxP mtx = i_this->mpMorf->getModel()->getAnmMtx(0x10); // mune (chest) joint
            cMtx_copy(mtx, *calc_mtx);
            boko->setMatrix(*calc_mtx);
            cXyz offset;
            offset.set(0.0f, 0.0f, 0.0f);
            MtxPosition(&offset, &boko->current.pos);
        }
    }
    
    i_this->m121F = 1;
    i_this->m0B34 = 0;
    i_this->m0B30 = 0;
}

/* 00000A1C-00000EE8       .text smoke_set_s__FP8bk_classf */
static void smoke_set_s(bk_class* i_this, f32) {
    /* Nonmatching */
}

/* 00000EE8-000011F0       .text ground_smoke_set__FP8bk_class */
static void ground_smoke_set(bk_class* i_this) {
    /* Nonmatching */
}

/* 000011F0-00001454       .text nodeCallBack__FP7J3DNodei */
static BOOL nodeCallBack(J3DNode*, int) {
    /* Nonmatching */
}

/* 00001454-00001564       .text nodeCallBack_P__FP7J3DNodei */
static BOOL nodeCallBack_P(J3DNode*, int) {
    /* Nonmatching */
}

/* 00001564-000019A4       .text search_check_draw__FP8bk_class */
static void search_check_draw(bk_class* i_this) {
    /* Nonmatching */
}

/* 000019A8-00001B88       .text br_draw__FP8bk_class */
static void br_draw(bk_class* i_this) {
    /* Nonmatching */
}

/* 00001B88-00001CD0       .text daBk_shadowDraw__FP8bk_class */
static BOOL daBk_shadowDraw(bk_class* i_this) {
    /* Nonmatching */
}

/* 00001CD0-00001F60       .text daBk_Draw__FP8bk_class */
static BOOL daBk_Draw(bk_class* i_this) {
    /* Nonmatching */
}

/* 00001F60-00002404       .text way_pos_check__FP8bk_classP4cXyz */
static void way_pos_check(bk_class* i_this, cXyz*) {
    /* Nonmatching */
}

/* 0000259C-00002864       .text ground_4_check__FP8bk_classisf */
static void ground_4_check(bk_class* i_this, int, s16, f32) {
    /* Nonmatching */
}

/* 00002864-00002C4C       .text daBk_other_bg_check__FP8bk_classP10fopAc_ac_c */
static void daBk_other_bg_check(bk_class* i_this, fopAc_ac_c*) {
    /* Nonmatching */
}

static fopAc_ac_c* target_info[10];
static s32 target_info_count;

/* 00002C4C-00002CD4       .text s_w_sub__FPvPv */
static void* s_w_sub(void* param_1, void*) {
    if (fopAc_IsActor(param_1) && fopAcM_GetName(param_1) == PROC_BOKO) {
        daBoko_c* boko = (daBoko_c*)param_1;
        // TODO: enum for boko type
        if (fopAcM_GetParam(boko) != 4 && !fopAcM_checkCarryNow(boko)) {
            if (target_info_count < (s32)ARRAY_SIZE(target_info)) {
                target_info[target_info_count] = boko;
                target_info_count++;
            }
        }
    }
    return NULL;
}

/* 00002CD4-00002FB0       .text search_wepon__FP8bk_class */
static u32 search_wepon(bk_class* i_this) {
    /* Nonmatching */
}

/* 00002FB0-0000302C       .text s_b_sub__FPvPv */
static void s_b_sub(void*, void*) {
    /* Nonmatching */
}

/* 0000302C-000033BC       .text search_bomb__FP8bk_classi */
static fopAc_ac_c* search_bomb(bk_class* i_this, int) {
    /* Nonmatching */
}

/* 000033BC-00003438       .text daBk_wepon_view_check__FP8bk_class */
static BOOL daBk_wepon_view_check(bk_class* i_this) {
    if (i_this->m02CC != 0) {
        return FALSE;
    }
    i_this->m1200 = search_wepon(i_this);
    if (i_this->m1200 != fpcM_ERROR_PROCESS_ID_e) {
        if (fopAcM_SearchByID(i_this->m1200)) {
            return TRUE;
        }
    }
    return FALSE;
}

/* 00003438-00003478       .text daBk_bomb_view_check__FP8bk_class */
static void daBk_bomb_view_check(bk_class* i_this) {
    /* Nonmatching */
}

/* 00003478-000034B8       .text daBk_bomb_check__FP8bk_class */
static BOOL daBk_bomb_check(bk_class* i_this) {
    i_this->m11F8 = search_bomb(i_this, 0);
    if (i_this->m11F8) {
        return TRUE;
    }
    return FALSE;
}

/* 000034B8-0000385C       .text daBk_player_bg_check__FP8bk_classP4cXyz */
static void daBk_player_bg_check(bk_class* i_this, cXyz*) {
    /* Nonmatching */
}

/* 0000385C-00003A18       .text daBk_player_view_check__FP8bk_classP4cXyzss */
static void daBk_player_view_check(bk_class* i_this, cXyz*, s16, s16) {
    /* Nonmatching */
}

/* 00003A18-00003A5C       .text daBk_player_way_check__FP8bk_class */
static BOOL daBk_player_way_check(bk_class* i_this) {
    fopAc_ac_c* player = dComIfGp_getPlayer(0);
    s16 angleDiff = i_this->current.angle.y - player->shape_angle.y;
    if (angleDiff < 0) {
        angleDiff = -angleDiff;
    }
    if ((u16)angleDiff < 0x4000) {
        return FALSE;
    }
    return TRUE;
}

/* 00003A5C-00003B2C       .text wait_set__FP8bk_class */
static void wait_set(bk_class* i_this) {
    /* Nonmatching */
}

/* 00003B2C-00003C34       .text walk_set__FP8bk_class */
static void walk_set(bk_class* i_this) {
    /* Nonmatching */
}

/* 00003C34-00003C74       .text fight_run_set__FP8bk_class */
static void fight_run_set(bk_class* i_this) {
    /* Nonmatching */
}

/* 00003C74-00004104       .text path_check__FP8bk_classUc */
static void path_check(bk_class* i_this, u8) {
    /* Nonmatching */
}

/* 00004104-0000488C       .text jyunkai__FP8bk_class */
static void jyunkai(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000488C-000048E4       .text ken_s_sub__FPvPv */
static void* ken_s_sub(void* param_1, void*) {
    if (fopAc_IsActor(param_1) && fopAcM_GetName(param_1) == PROC_ITEM) {
        daItem_c* item = (daItem_c*)param_1;
        if (item->getItemNo() == DROPPED_SWORD) {
            return param_1;
        }
    }
    return NULL;
}

/* 000048E4-000053E0       .text stand__FP8bk_class */
static void stand(bk_class* i_this) {
    /* Nonmatching */
}

/* 000053E0-000054E0       .text s_s_sub__FPvPv */
static void s_s_sub(void*, void*) {
    /* Nonmatching */
}

/* 000054E0-00005D40       .text stand2__FP8bk_class */
static void stand2(bk_class* i_this) {
    /* Nonmatching */
}

/* 00005D40-00006218       .text path_run__FP8bk_class */
static void path_run(bk_class* i_this) {
    /* Nonmatching */
}

/* 00006218-0000647C       .text attack_set__FP8bk_classUc */
static void attack_set(bk_class* i_this, u8) {
    /* Nonmatching */
}

u16 learn_check;

/* 0000647C-000064D8       .text shot_s_sub__FPvPv */
static void* shot_s_sub(void* param_1, void*) {
    if (fopAc_IsActor(param_1) && learn_check & 0x400 && fopAcM_GetName(param_1) == PROC_HIMO2) {
        return param_1;
    }
    return NULL;
}

/* 000064D8-000073B8       .text fight_run__FP8bk_class */
static void fight_run(bk_class* i_this) {
    /* Nonmatching */
}

/* 000073B8-000075E8       .text yari_hit_check__FP8bk_class */
static void yari_hit_check(bk_class* i_this) {
    /* Nonmatching */
}

/* 000075E8-00007EF4       .text fight__FP8bk_class */
static void fight(bk_class* i_this) {
    /* Nonmatching */
}

/* 00007EF4-00008108       .text p_lost__FP8bk_class */
static void p_lost(bk_class* i_this) {
    /* Nonmatching */
}

/* 00008108-00008470       .text b_nige__FP8bk_class */
static void b_nige(bk_class* i_this) {
    /* Nonmatching */
}

/* 00008470-00008580       .text defence__FP8bk_class */
static void defence(bk_class* i_this) {
    /* Nonmatching */
}

/* 00008580-00008654       .text oshi__FP8bk_class */
static void oshi(bk_class* i_this) {
    /* Nonmatching */
}

/* 00008654-00008C38       .text hukki__FP8bk_class */
static void hukki(bk_class* i_this) {
    /* Nonmatching */
}

/* 00008C38-00008D1C       .text aite_miru__FP8bk_class */
static void aite_miru(bk_class* i_this) {
    /* Nonmatching */
}

/* 00008D1C-00008ECC       .text fail__FP8bk_class */
static void fail(bk_class* i_this) {
    /* Nonmatching */
}

/* 00008ECC-000090E0       .text yogan_fail__FP8bk_class */
static void yogan_fail(bk_class* i_this) {
    /* Nonmatching */
}

/* 000090E0-0000924C       .text water_fail__FP8bk_class */
static void water_fail(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000924C-00009944       .text wepon_search__FP8bk_class */
static void wepon_search(bk_class* i_this) {
    /* Nonmatching */
}

/* 00009944-00009AFC       .text d_dozou__FP8bk_class */
static void d_dozou(bk_class* i_this) {
    /* Nonmatching */
}

/* 00009AFC-00009B0C       .text carry__FP8bk_class */
static void carry(bk_class* i_this) {
    i_this->speed.y = 0.0f;
}

/* 00009B0C-00009DF0       .text carry_drop__FP8bk_class */
static void carry_drop(bk_class* i_this) {
    /* Nonmatching */
}

/* 00009DF0-00009F1C       .text d_mahi__FP8bk_class */
static void d_mahi(bk_class* i_this) {
    /* Nonmatching */
}

/* 00009F1C-0000A350       .text tubo_wait__FP8bk_class */
static void tubo_wait(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000A350-0000A630       .text z_demo_1__FP8bk_class */
static void z_demo_1(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000A630-0000A9BC       .text b_hang__FP8bk_class */
static void b_hang(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000A9BC-0000AC6C       .text rope_on__FP8bk_class */
static void rope_on(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000AC6C-0000AC84       .text search_target__FP8bk_class */
static BOOL search_target(bk_class* i_this) {
    i_this->mDamageReaction.m714 = dComIfGp_getPlayer(0);
    return FALSE;
}

/* 0000AC84-0000B25C       .text Bk_move__FP8bk_class */
static void Bk_move(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000B25C-0000B324       .text bk_eye_tex_anm__FP8bk_class */
static void bk_eye_tex_anm(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000B324-0000BC98       .text damage_check__FP8bk_class */
static void damage_check(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000BCD4-0000BD30       .text s_s2_sub__FPvPv */
static void* s_s2_sub(void* param_1, void*) {
    if (fopAc_IsActor(param_1) && fopAcM_GetName(param_1) == PROC_OBJ_SEARCH) {
        if (daObj_Search::Act_c::getFindFlag()) {
            return param_1;
        }
    }
    return NULL;
}

/* 0000BD30-0000C2D0       .text waki_set__FP8bk_class */
static void waki_set(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000C2D0-0000CC68       .text demo_camera__FP8bk_class */
static void demo_camera(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000CC68-0000CD00       .text tate_mtx_set__FP8bk_class */
static void tate_mtx_set(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000CD00-0000CE18       .text bou_mtx_set__FP8bk_class */
static void bou_mtx_set(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000CE18-0000DD1C       .text daBk_Execute__FP8bk_class */
static BOOL daBk_Execute(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000DD1C-0000DD24       .text daBk_IsDelete__FP8bk_class */
static BOOL daBk_IsDelete(bk_class* i_this) {
    return TRUE;
}

/* 0000DD24-0000DDD8       .text daBk_Delete__FP8bk_class */
static BOOL daBk_Delete(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000DDD8-0000E2C8       .text useHeapInit__FP10fopAc_ac_c */
static BOOL useHeapInit(fopAc_ac_c* i_this) {
    /* Nonmatching */
}

/* 0000E310-0000EA2C       .text daBk_Create__FP10fopAc_ac_c */
static s32 daBk_Create(fopAc_ac_c* i_this) {
    /* Nonmatching */
    fopAcM_SetupActor(i_this, bk_class);
}

static actor_method_class l_daBk_Method = {
    (process_method_func)daBk_Create,
    (process_method_func)daBk_Delete,
    (process_method_func)daBk_Execute,
    (process_method_func)daBk_IsDelete,
    (process_method_func)daBk_Draw,
};

actor_process_profile_definition g_profile_BK = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 7,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_BK,
    /* Proc SubMtd  */ &g_fpcLf_Method.mBase,
    /* Size         */ sizeof(bk_class),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x00B0,
    /* Actor SubMtd */ &l_daBk_Method,
    /* Status       */ fopAcStts_CULL_e | fopAcStts_UNK40000_e | fopAcStts_UNK80000_e,
    /* Group        */ fopAc_ENEMY_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
