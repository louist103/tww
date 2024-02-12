//
// Generated by dtk
// Translation Unit: d_cc_uty.cpp
//

#include "d/d_cc_uty.h"
#include "d/d_com_inf_game.h"
#include "d/actor/d_a_player.h"
#include "d/actor/d_a_bomb.h"
#include "d/actor/d_a_tsubo.h"
#include "d/actor/d_a_mt.h"
#include "d/d_procname.h"
#include "d/d_s_play.h"

/* 800AE938-800AE9E8       .text cc_pl_cut_bit_get__Fv */
u16 cc_pl_cut_bit_get() {
    daPy_py_c* player = daPy_getPlayerActorClass();
    u16 r3 = 0x00;
    if (player->getCutType() == 1) {
        r3 = 0x01;
    } else if (player->getCutType() == 2) {
        r3 = 0x02;
    } else if (player->getCutType() == 3) {
        r3 = 0x04;
    } else if (player->getCutType() == 4) {
        r3 = 0x08;
    } else if (player->getCutType() == 5) {
        r3 = 0x10;
    } else if (player->getCutType() == 6) {
        r3 = 0x20;
    } else if (player->getCutType() == 7) {
        r3 = 0x40;
    } else if (player->getCutType() == 8 || player->getCutType() == 9) {
        r3 = 0x80;
    } else if (player->getCutType() == 10) {
        r3 = 0x100;
    }
    return r3;
}

/* 800AE9E8-800AEA60       .text at_se_get__FP8cCcD_Obj */
u32 at_se_get(cCcD_Obj* obj) {
    dCcD_GObjInf* gObjInf = dCcD_GetGObjInf(obj);
    if (gObjInf->ChkAtType(AT_TYPE_SKULL_HAMMER | AT_TYPE_STALFOS_MACE)) {
        return JA_SE_LK_HAMMER_HIT;
    } else if (gObjInf->GetAtSe() == dCcD_SE_UNK4) {
        return JA_SE_LK_W_WEP_HIT;
    } else if (gObjInf->GetAtSe() == dCcD_SE_UNK5) {
        return JA_SE_LK_MS_WEP_HIT;
    } else if (gObjInf->GetAtSe() == dCcD_SE_ARROW) {
        return JA_SE_LK_ARROW_HIT;
    } else if (gObjInf->GetAtSe() == dCcD_SE_HOOKSHOT) {
        return JA_SE_LK_HS_SPIKE;
    } else {
        return JA_SE_LK_SW_HIT_S;
    }
}

/* 800AEA60-800AEAD8       .text at_se_getC__FP8cCcD_Obj */
u32 at_se_getC(cCcD_Obj* obj) {
    dCcD_GObjInf* gObjInf = dCcD_GetGObjInf(obj);
    if (gObjInf->ChkAtType(AT_TYPE_SKULL_HAMMER | AT_TYPE_STALFOS_MACE)) {
        return JA_SE_LK_HAMMER_HIT;
    } else if (gObjInf->GetAtSe() == dCcD_SE_UNK4) {
        return JA_SE_LK_W_WEP_CRT_HIT;
    } else if (gObjInf->GetAtSe() == dCcD_SE_UNK5) {
        return JA_SE_LK_MS_WEP_CRT_HIT;
    } else if (gObjInf->GetAtSe() == dCcD_SE_ARROW) {
        return JA_SE_LK_ARROW_HIT;
    } else if (gObjInf->GetAtSe() == dCcD_SE_HOOKSHOT) {
        return JA_SE_LK_HS_SPIKE;
    } else {
        return JA_SE_LK_SW_CRT_HIT;
    }
}

/* 800AEAD8-800AEB50       .text def_se_set__FP10fopAc_ac_cP8cCcD_ObjUl */
void def_se_set(fopAc_ac_c* actor, cCcD_Obj* obj, unsigned long r5) {
    fopAcM_seStart(actor, at_se_get(obj), r5);
}

/* 800AEB50-800AEBCC       .text def_se_set_p__FP10fopAc_ac_cP4cXyzP8cCcD_ObjUl */
void def_se_set_p(fopAc_ac_c* actor, cXyz* sePos, cCcD_Obj* obj, unsigned long r6) {
    mDoAud_seStart(at_se_get(obj), sePos, r6, dComIfGp_getReverb(fopAcM_GetRoomNo(actor)));
}

/* 800AEBCC-800AEEF8       .text at_power_check__FP8CcAtInfo */
fopAc_ac_c* at_power_check(CcAtInfo* atInfo) {
    daPy_py_c* player = daPy_getPlayerActorClass();
    if (atInfo->mpObj == NULL) {
        return NULL;
    }
    atInfo->mpActor = atInfo->mpObj->GetAc();
    atInfo->mResultingAttackType = 0xC;
    atInfo->mDamage = 0;
    
    if (atInfo->mpObj->ChkAtType(AT_TYPE_WATER)) {
        atInfo->mResultingAttackType = 0x4;
        return atInfo->mpActor;
    } else if (atInfo->mpObj->ChkAtType(AT_TYPE_WIND)) {
        atInfo->mResultingAttackType = 0x8;
        return atInfo->mpActor;
    } else if (atInfo->mpObj->ChkAtType(AT_TYPE_UNK20000)) {
        atInfo->mResultingAttackType = 0x5;
        return atInfo->mpActor;
    } else if (atInfo->mpObj->ChkAtType(AT_TYPE_FIRE | AT_TYPE_FIRE_ARROW)) {
        atInfo->mResultingAttackType = 0x5;
    }
    
    if (atInfo->mpActor) {
        atInfo->mDamage = atInfo->mpObj->GetAtAtp();
        
        if (fopAcM_GetName(atInfo->mpActor) == PROC_PLAYER) {
            if (atInfo->mpObj->ChkAtType(AT_TYPE_SKULL_HAMMER)) {
                atInfo->mResultingAttackType = 0x9;
            } else {
                atInfo->mResultingAttackType = 0x1;
                atInfo->mPlCutBit = cc_pl_cut_bit_get();
                
                if (player->getCutCount() == 3) {
                    atInfo->mHitSoundId = 1;
                } else if (player->getCutCount() == 4) {
                    atInfo->mHitSoundId = 4;
                } else if (player->getCutType() == 0xA) {
                    atInfo->mHitSoundId = 2;
                } else if (player->getCutType() == 0x5 || player->getCutType() == 0xF || player->getCutType() == 0x10) {
                    atInfo->mHitSoundId = 3;
                } else {
                    atInfo->mHitSoundId = 0;
                }
            }
        } else if (fopAcM_GetName(atInfo->mpActor) == PROC_BOMB) {
            daBomb_c* bomb = (daBomb_c*)atInfo->mpActor;
            if (bomb->chk_state(daBomb_c::STATE_8)) {
                atInfo->mResultingAttackType = 0xD;
            } else {
                atInfo->mResultingAttackType = 0x2;
            }
            atInfo->mPlCutBit = 0x200;
        } else if (fopAcM_GetName(atInfo->mpActor) == PROC_Bomb2) {
            atInfo->mResultingAttackType = 0x2;
            atInfo->mPlCutBit = 0x200;
        } else if (fopAcM_GetName(atInfo->mpActor) == PROC_HIMO2) {
            atInfo->mResultingAttackType = 0xE;
            atInfo->mPlCutBit = 0x400;
        } else if (fopAcM_GetName(atInfo->mpActor) == PROC_BOOMERANG) {
            atInfo->mResultingAttackType = 0xA;
            atInfo->mPlCutBit = 0x800;
        } else if (fopAcM_GetName(atInfo->mpActor) == PROC_ARROW) {
            atInfo->mPlCutBit = 0x1000;
        } else if (fopAcM_GetName(atInfo->mpActor) == PROC_BDK) {
            atInfo->mResultingAttackType = 0xB;
        } else if (fopAcM_GetName(atInfo->mpActor) == PROC_TSUBO) {
            daTsubo::Act_c* tsubo = (daTsubo::Act_c*)atInfo->mpActor;
            if (tsubo->prm_get_type() == daTsubo::Act_c::TYPE_WATER_JUG) {
                atInfo->mResultingAttackType = 0x4;
            } else {
                atInfo->mResultingAttackType = 0x3;
            }
        } else if (fopAcM_GetName(atInfo->mpActor) == PROC_MO2) {
            atInfo->mResultingAttackType = 0x7;
            if (atInfo->mDamage > 2) {
                atInfo->mDamage = 2;
            }
        } else if (fopAcM_GetName(atInfo->mpActor) == PROC_MT) {
            atInfo->mResultingAttackType = 0x6;
            atInfo->mDamage = 4;
        }
    }
        
    atInfo->mbDead = false;
    if (fopAcM_GetName(atInfo->mpActor) == PROC_PLAYER) {
        dCcD_GObjInf* gObjInf = dCcD_GetGObjInf(atInfo->mpObj);
        if (gObjInf->GetAtSpl() == 1) {
            atInfo->mbDead = true;
        }
    } else if (atInfo->mDamage >= 2) {
        atInfo->mbDead = true;
    }
    
    return atInfo->mpActor;
}

/* 800AEEF8-800AF368       .text cc_at_check__FP10fopAc_ac_cP8CcAtInfo */
fopAc_ac_c* cc_at_check(fopAc_ac_c* tgActor, CcAtInfo* atInfo) {
    atInfo->mHitSoundId = 0;
    atInfo->mpActor = at_power_check(atInfo);
    
    s8 pauseTime;
    
    if (atInfo->mpActor) {
        mDoAud_onEnemyDamage();
        
        f32 f2, f0;
        if (atInfo->mpActor->speed.abs() > 50.0f) {
            f2 = atInfo->mpActor->speed.x;
            f0 = atInfo->mpActor->speed.z;
        } else {
            f2 = tgActor->current.pos.x - atInfo->mpActor->current.pos.x;
            f0 = tgActor->current.pos.z - atInfo->mpActor->current.pos.z;
        }
        atInfo->m0C.y = cM_atan2s(-f2, -f0);
        
        if (atInfo->mpObj->ChkAtType(AT_TYPE_HOOKSHOT)) {
            if (fopAcM_checkStatus(tgActor, fopAcStts_UNK80000_e | fopAcStts_HOOK_CARRY_e | fopAcStts_UNK200000_e)) {
                atInfo->mDamage = 0;
            }
        }
        
        if (fopAcM_GetName(atInfo->mpActor) == PROC_HIMO2 && tgActor->mStealItemLeft != 0) {
            tgActor->mStealItemLeft--;
            fopAcM_createStealItem(&tgActor->current.pos, tgActor->mItemTableIdx, tgActor->current.roomNo, NULL, tgActor->mStealItemBitNo);
            tgActor->mStealItemBitNo++;
            atInfo->mDamage = 0;
        }
        
        if ((s8)atInfo->mDamage > 0) {
            tgActor->mHealth -= atInfo->mDamage;
        }
        
        if (tgActor->mHealth <= 0) {
            atInfo->mbDead = true;
            
            fopAcM_seStart(tgActor, JA_SE_LK_LAST_HIT, 0);
            
            pauseTime = 6 + g_regHIO.mChild->mShortRegs[7];
            
            if (atInfo->pParticlePos) {
                dComIfGp_particle_set(0x10, atInfo->pParticlePos);
                cXyz scale;
                scale.x = scale.y = scale.z = 2.0f;
                csXyz angle;
                angle.x = angle.z = 0;
                angle.y = fopAcM_searchPlayerAngleY(tgActor);
                dComIfGp_particle_set(dPa_name::ID_COMMON_NORMAL_HIT, atInfo->pParticlePos, &angle, &scale);
            }
        } else {
            u32 r29 = fopAcM_GetName(tgActor) == PROC_ST ? 0x33 : 0x20;
            if (atInfo->mbDead) {
                fopAcM_seStart(tgActor, at_se_getC(atInfo->mpObj), r29);
                if (atInfo->mResultingAttackType == 9) {
                    pauseTime = 6;
                } else {
                    pauseTime = 4 + g_regHIO.mChild->mShortRegs[6];
                }
            } else {
                if (fopAcM_GetName(tgActor) == PROC_MT) {
                    mt_class* mt = (mt_class*)tgActor;
                    if (mt->m454 == 2) {
                        fopAcM_seStart(tgActor, JA_SE_OBJ_MG_BALL_DMG, 0);
                    } else {
                        fopAcM_seStart(tgActor, at_se_get(atInfo->mpObj), r29);
                    }
                } else {
                    fopAcM_seStart(tgActor, at_se_get(atInfo->mpObj), r29);
                }
                pauseTime = 1 + g_regHIO.mChild->mShortRegs[5];
            }
        }
        
        if (atInfo->mResultingAttackType == 1) {
            dScnPly_ply_c::setPauseTimer(pauseTime);
        }
        
        if (atInfo->mDamage != 0) {
            mDoAud_bgmHitSound(atInfo->mHitSoundId);
        }
    }
    
    return atInfo->mpActor;
}
