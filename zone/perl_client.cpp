#include "../common/features.h"

#ifdef EMBPERL_XS_CLASSES

#include "../common/global_define.h"
#include "embperl.h"

#ifdef seed
#undef seed
#endif

#include "client.h"
#include "expedition.h"
#include "titles.h"
#include "dialogue_window.h"

#ifdef THIS        /* this macro seems to leak out on some systems */
#undef THIS
#endif

#define VALIDATE_THIS_IS_CLIENT \
	do { \
		if (sv_derived_from(ST(0), "Client")) { \
			IV tmp = SvIV((SV*)SvRV(ST(0))); \
			THIS = INT2PTR(Client*, tmp); \
		} else { \
			Perl_croak(aTHX_ "THIS is not of type Client"); \
		} \
		if (THIS == nullptr) { \
			Perl_croak(aTHX_ "THIS is nullptr, avoiding crash."); \
		} \
	} while (0);

XS(XS_Client_SendSound); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SendSound) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::SendSound(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->SendSound();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_Save); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_Save) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::Save(THIS, uint8 commit_now)"); // @categories Script Utility
	{
		Client *THIS;
		bool  RETVAL;
		uint8 iCommitNow = (uint8) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->Save(iCommitNow);
		ST(0)            = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_SaveBackup); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SaveBackup) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::SaveBackup(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->SaveBackup();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_Connected); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_Connected) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::Connected(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->Connected();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_InZone); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_InZone) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::InZone(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->InZone();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_Kick); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_Kick) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::Kick(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->Kick("Perl Quest");
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_Disconnect); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_Disconnect) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::Disconnect(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->Disconnect();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_IsLD); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_IsLD) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::IsLD(THIS)"); // @categories Account and Character
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->IsLD();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_WorldKick); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_WorldKick) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::WorldKick(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->WorldKick();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SendToGuildHall); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SendToGuildHall) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::SendToGuildHall(THIS)"); // @categories Script Utility, Guild
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->SendToGuildHall();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetAnon); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetAnon) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetAnon(THIS)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetAnon();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_SetAnon); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetAnon) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetAnon(THIS, uint8 anon_flag)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint8 anon_flag = (uint8) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetAnon(anon_flag);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetAFK); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetAFK) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetAFK(THIS)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetAFK();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_SetAFK); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetAFK) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetAFK(THIS, uint8 afk_flag)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint8 afk_flag = (uint8) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetAFK(afk_flag);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_Duck); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_Duck) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::Duck(THIS)"); // @categories Account and Character
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->Duck();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_DyeArmorBySlot); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_DyeArmorBySlot) {
	dXSARGS;
	if (items != 5 && items != 6)
		Perl_croak(aTHX_ "Usage: Client::DyeArmorBySlot(THIS, uint8 slot, uint8 red, uint8 green, uint8 blue, [uint8 use_tint = 0x00])"); // @categories Account and Character, Inventory and Items
	{
		Client *THIS;
		uint8 slot = (uint8) SvUV(ST(1));
		uint8 red = (uint8) SvUV(ST(2));
		uint8 green = (uint8) SvUV(ST(3));
		uint8 blue = (uint8) SvUV(ST(4));
		uint8 use_tint = 0x00;
		if (items == 6) {
			use_tint = (uint8) SvUV(ST(5));
		}
		VALIDATE_THIS_IS_CLIENT;
		THIS->DyeArmorBySlot(slot, red, green, blue, use_tint);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_Stand); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_Stand) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::Stand(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->Stand();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetGM); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetGM) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetGM(THIS, bool toggle)"); // @categories Account and Character
	{
		Client *THIS;
		bool toggle = (bool) SvTRUE(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetGM(toggle);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetPVP); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetPVP) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetPVP(THIS, bool toggle)"); // @categories Account and Character
	{
		Client *THIS;
		bool toggle = (bool) SvTRUE(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetPVP(toggle);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetPVP); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetPVP) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetPVP(THIS)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetPVP();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_GetGM); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetGM) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetGM(THIS)"); // @categories Account and Character
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetGM();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_SetBaseClass); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetBaseClass) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetBaseClass(THIS, uint32 class_id)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint32 i = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetBaseClass(i);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetBaseRace); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetBaseRace) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetBaseRace(THIS, uint32 race_id)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint32 i = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetBaseRace(i);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetBaseGender); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetBaseGender) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetBaseGender(THIS, uint32 gender_id)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint32 i = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetBaseGender(i);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetBaseFace); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetBaseFace) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetBaseFace(THIS)"); // @categories Stats and Attributes
	{
		Client *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetBaseFace();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetLanguageSkill); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetLanguageSkill) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetLanguageSkill(THIS, uint16 lanuage_id)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint8  RETVAL;
		dXSTARG;
		uint16 n = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetLanguageSkill(n);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetLDoNPointsTheme); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetLDoNPointsTheme) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetLDoNPointsTheme(THIS, int32 theme)"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		int32  theme_out = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetLDoNPointsTheme(theme_out);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetBaseSTR); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetBaseSTR) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetBaseSTR(THIS)"); // @categories Stats and Attributes
	{
		Client *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetBaseSTR();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetBaseSTA); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetBaseSTA) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetBaseSTA(THIS)"); // @categories Stats and Attributes
	{
		Client *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetBaseSTA();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetBaseCHA); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetBaseCHA) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetBaseCHA(THIS)"); // @categories Stats and Attributes
	{
		Client *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetBaseCHA();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetBaseDEX); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetBaseDEX) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetBaseDEX(THIS)"); // @categories Stats and Attributes
	{
		Client *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetBaseDEX();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetBaseINT); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetBaseINT) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetBaseINT(THIS)"); // @categories Stats and Attributes
	{
		Client *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetBaseINT();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetBaseAGI); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetBaseAGI) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetBaseAGI(THIS)"); // @categories Stats and Attributes
	{
		Client *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetBaseAGI();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetBaseWIS); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetBaseWIS) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetBaseWIS(THIS)"); // @categories Stats and Attributes
	{
		Client *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetBaseWIS();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetWeight); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetWeight) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetWeight(THIS)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint16 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetWeight();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetEXP); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetEXP) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetEXP(THIS)"); // @categories Experience and Level
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetEXP();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetAAExp); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetAAExp) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetAAExp(THIS)"); // @categories Alternative Advancement, Experience and Level
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetAAXP();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetAAPercent);
XS(XS_Client_GetAAPercent) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetAAPercent(THIS)"); // @categories Alternative Advancement, Experience and Level
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetAAPercent();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetTotalSecondsPlayed); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetTotalSecondsPlayed) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetTotalSecondsPlayed(THIS)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetTotalSecondsPlayed();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_UpdateLDoNPoints); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_UpdateLDoNPoints) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::UpdateLDoNPoints(THIS, uint32 theme_id, int points)"); // @categories Currency and Points
	{
		Client *THIS;
		bool RETVAL;
		uint32 theme_id = (uint32) SvUV(ST(1));
		int points = (int) SvIV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->UpdateLDoNPoints(theme_id, points);
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_SetDeity); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetDeity) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetDeity(THIS, uint32 deity_id)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint32 i = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetDeity(i);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_AddEXP); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_AddEXP) {
	dXSARGS;
	if (items < 2 || items > 4)
		Perl_croak(aTHX_ "Usage: Client::AddEXP(THIS, uint32 experience_points)"); // @categories Experience and Level
	{
		Client *THIS;
		uint32 add_exp = (uint32) SvUV(ST(1));
		uint8  conlevel;
		bool   resexp;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 3)
			conlevel = 0xFF;
		else {
			conlevel = (uint8) SvUV(ST(2));
		}

		if (items < 4)
			resexp = false;
		else {
			resexp = (bool) SvTRUE(ST(3));
		}

		THIS->AddEXP(add_exp, conlevel, resexp);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetEXP); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetEXP) {
	dXSARGS;
	if (items < 3 || items > 4)
		Perl_croak(aTHX_ "Usage: Client::SetEXP(THIS, uint32 experience_points, uint32 aa_experience_points, [bool resexp=false])"); // @categories Experience and Level
	{
		Client *THIS;
		uint32 set_exp  = (uint32) SvUV(ST(1));
		uint32 set_aaxp = (uint32) SvUV(ST(2));
		bool   resexp;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 4)
			resexp = false;
		else {
			resexp = (bool) SvTRUE(ST(3));
		}

		THIS->SetEXP(set_exp, set_aaxp, resexp);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetBindPoint); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetBindPoint) {
	dXSARGS;
	if (items < 1 || items > 7)
		Perl_croak(aTHX_ "Usage: Client::SetBindPoint(THIS, [int to_zone = -1, int to_instance = 0, float new_x = 0.0f, float new_y = 0.0f, float new_z = 0.0f, float new_heading = 0.0f])"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		int   to_zone = -1;
		int   to_instance = 0;
		float new_x = 0.0f, new_y = 0.0f, new_z = 0.0f, new_heading = 0.0f;
		VALIDATE_THIS_IS_CLIENT;
		if (items > 1)
			to_zone = (int) SvIV(ST(1));
		if (items > 2)
			to_instance = (int) SvIV(ST(2));
		if (items > 3)
			new_x = (float) SvNV(ST(3));
		if (items > 4)
			new_y = (float) SvNV(ST(4));
		if (items > 5)
			new_z = (float) SvNV(ST(5));
		if (items > 6)
			new_heading = (float) SvNV(ST(6));

		THIS->SetBindPoint2(0, to_zone, to_instance, glm::vec4(new_x, new_y, new_z, new_heading));
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetBindX); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetBindX) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Client::GetBindX(int index = 0)"); // @categories Account and Character
	{
		Client *THIS;
		int   index = 0;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		if (items == 1)
			index = 0;
		else if (items == 2) {
			index = (uint32) SvUV(ST(1));
		}

		RETVAL = THIS->GetBindX(index);
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetBindY); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetBindY) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Client::GetBindY(int index = 0)"); // @categories Account and Character
	{
		Client *THIS;
		int   index = 0;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		if (items == 1)
			index = 0;
		else if (items == 2) {
			index = (uint32) SvUV(ST(1));;
		}

		RETVAL = THIS->GetBindY(index);
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetBindZ); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetBindZ) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Client::GetBindZ(int index = 0)"); // @categories Account and Character
	{
		Client *THIS;
		int   index = 0;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		if (items == 1)
			index = 0;
		else if (items == 2) {
			index = (uint32) SvUV(ST(1));
		}

		RETVAL = THIS->GetBindZ(index);
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetBindHeading); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetBindHeading) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Client::GetBindHeading(int index = 0)"); // @categories Account and Character
	{
		Client *THIS;
		int   index = 0;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		if (items == 1)
			index = 0;
		else if (items == 2) {
			index = (uint32) SvUV(ST(1));
		}

		RETVAL = THIS->GetBindHeading(index);
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetBindZoneID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetBindZoneID) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Client::GetBindZoneID(int index = 0)"); // @categories Account and Character
	{
		Client *THIS;
		uint32 index = 0;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		if (items == 1)
			index = 0;
		else if (items == 2) {
			index = (uint32) SvUV(ST(1));
		}

		RETVAL = THIS->GetBindZoneID(index);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}


XS(XS_Client_MovePC); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_MovePC) {
	dXSARGS;
	if (items != 6)
		Perl_croak(aTHX_ "Usage: Client::MovePC(THIS, uint32 zone_id, float x, float y, float z, float heading)"); // @categories Script Utility
	{
		Client *THIS;
		uint32 zoneID  = (uint32) SvUV(ST(1));
		float  x       = (float) SvNV(ST(2));
		float  y       = (float) SvNV(ST(3));
		float  z       = (float) SvNV(ST(4));
		float  heading = (float) SvNV(ST(5));
		VALIDATE_THIS_IS_CLIENT;
		if (THIS->IsClient()) {
			THIS->MovePC(zoneID, x, y, z, heading);
		} else {
			if (THIS->IsMerc()) {
				LogDebug("[CLIENT] Perl(XS_Client_MovePC) attempted to process a type Merc reference");
			}
#ifdef BOTS
			else if (THIS->IsBot()) {
				LogDebug("[CLIENT] Perl(XS_Client_MovePC) attempted to process a type Bot reference");
			}
#endif
			else if (THIS->IsNPC()) {
				LogDebug("[CLIENT] Perl(XS_Client_MovePC) attempted to process a type NPC reference");
			}
			else {
				LogDebug("[CLIENT] Perl(XS_Client_MovePC) attempted to process an Unknown type reference");
			}

			Perl_croak(aTHX_ "THIS is not of type Client");
		}

	}
	XSRETURN_EMPTY;
}

XS(XS_Client_MovePCInstance); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_MovePCInstance) {
	dXSARGS;
	if (items != 7)
		Perl_croak(aTHX_ "Usage: Client::MovePCInstance(THIS, uint32 zone_id, uint32 instance_id, float x, float y, float z, float heading)"); // @categories Adventures and Expeditions, Script Utility
	{
		Client *THIS;
		uint32 zoneID     = (uint32) SvUV(ST(1));
		uint32 instanceID = (uint32) SvUV(ST(2));
		float  x          = (float) SvNV(ST(3));
		float  y          = (float) SvNV(ST(4));
		float  z          = (float) SvNV(ST(5));
		float  heading    = (float) SvNV(ST(6));
		VALIDATE_THIS_IS_CLIENT;
		if (THIS->IsClient()) {
			THIS->MovePC(zoneID, instanceID, x, y, z, heading);
		} else {
			if (THIS->IsMerc()) {
				LogDebug("[CLIENT] Perl(XS_Client_MovePCInstance) attempted to process a type Merc reference");
			}
#ifdef BOTS
			else if (THIS->IsBot()) {
				LogDebug("[CLIENT] Perl(XS_Client_MovePCInstance) attempted to process a type Bot reference");
			}
#endif
			else if (THIS->IsNPC()) {
				LogDebug("[CLIENT] Perl(XS_Client_MovePCInstance) attempted to process a type NPC reference");
			}
			else {
				LogDebug("[CLIENT] Perl(XS_Client_MovePCInstance) attempted to process an Unknown type reference");
			}

			Perl_croak(aTHX_ "THIS is not of type Client");

			Perl_croak(aTHX_ "THIS is not of type Client");
		}
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_MoveZone); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_MoveZone) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::MoveZone(THIS, string zone_short_name)"); // @categories Script Utility
	{
		Client *THIS;
		const char *zone_short_name  = (const char *) SvPV_nolen(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		if (THIS->IsClient()) {
			THIS->MoveZone(zone_short_name);
		} else {
			if (THIS->IsMerc()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZone) attempted to process a type Merc reference");
			}
#ifdef BOTS
			else if (THIS->IsBot()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZone) attempted to process a type Bot reference");
			}
#endif
			else if (THIS->IsNPC()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZone) attempted to process a type NPC reference");
			}
			else {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZone) attempted to process an Unknown type reference");
			}

			Perl_croak(aTHX_ "THIS is not of type Client");
		}

	}
	XSRETURN_EMPTY;
}

XS(XS_Client_MoveZoneGroup); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_MoveZoneGroup) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::MoveZoneGroup(THIS, string zone_short_name)"); // @categories Script Utility, Group
	{
		Client *THIS;
		const char *zone_short_name  = (const char *) SvPV_nolen(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		if (THIS->IsClient()) {
			THIS->MoveZoneGroup(zone_short_name);
		} else {
			if (THIS->IsMerc()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneGroup) attempted to process a type Merc reference");
			}
#ifdef BOTS
			else if (THIS->IsBot()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneGroup) attempted to process a type Bot reference");
			}
#endif
			else if (THIS->IsNPC()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneGroup) attempted to process a type NPC reference");
			}
			else {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneGroup) attempted to process an Unknown type reference");
			}

			Perl_croak(aTHX_ "THIS is not of type Client");
		}

	}
	XSRETURN_EMPTY;
}

XS(XS_Client_MoveZoneRaid); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_MoveZoneRaid) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::MoveZoneRaid(THIS, string zone_short_name)"); // @categories Script Utility, Raid
	{
		Client *THIS;
		const char *zone_short_name  = (const char *) SvPV_nolen(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		if (THIS->IsClient()) {
			THIS->MoveZoneRaid(zone_short_name);
		} else {
			if (THIS->IsMerc()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneRaid) attempted to process a type Merc reference");
			}
#ifdef BOTS
			else if (THIS->IsBot()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneRaid) attempted to process a type Bot reference");
			}
#endif
			else if (THIS->IsNPC()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneRaid) attempted to process a type NPC reference");
			}
			else {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneRaid) attempted to process an Unknown type reference");
			}

			Perl_croak(aTHX_ "THIS is not of type Client");
		}

	}
	XSRETURN_EMPTY;
}

XS(XS_Client_MoveZoneInstance); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_MoveZoneInstance) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::MoveZoneInstance(THIS, uint16 instance_id)"); // @categories Adventures and Expeditions, Script Utility
	{
		Client *THIS;
		uint16 instance_id  = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		if (THIS->IsClient()) {
			THIS->MoveZoneInstance(instance_id);
		} else {
			if (THIS->IsMerc()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneInstance) attempted to process a type Merc reference");
			}
#ifdef BOTS
			else if (THIS->IsBot()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneInstance) attempted to process a type Bot reference");
			}
#endif
			else if (THIS->IsNPC()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneInstance) attempted to process a type NPC reference");
			}
			else {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneInstance) attempted to process an Unknown type reference");
			}

			Perl_croak(aTHX_ "THIS is not of type Client");
		}

	}
	XSRETURN_EMPTY;
}

XS(XS_Client_MoveZoneInstanceGroup); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_MoveZoneInstanceGroup) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::MoveZoneInstanceGroup(THIS, uint16 instance_id)"); // @categories Adventures and Expeditions, Script Utility, Group
	{
		Client *THIS;
		uint16 instance_id  = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		if (THIS->IsClient()) {
			THIS->MoveZoneInstanceGroup(instance_id);
		} else {
			if (THIS->IsMerc()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneInstanceGroup) attempted to process a type Merc reference");
			}
#ifdef BOTS
			else if (THIS->IsBot()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneInstanceGroup) attempted to process a type Bot reference");
			}
#endif
			else if (THIS->IsNPC()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneInstanceGroup) attempted to process a type NPC reference");
			}
			else {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneInstanceGroup) attempted to process an Unknown type reference");
			}

			Perl_croak(aTHX_ "THIS is not of type Client");
		}

	}
	XSRETURN_EMPTY;
}

XS(XS_Client_MoveZoneInstanceRaid); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_MoveZoneInstanceRaid) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::MoveZoneInstanceRaid(THIS, uint16 instance_id)"); // @categories Adventures and Expeditions, Script Utility, Raid
	{
		Client *THIS;
		uint16 instance_id  = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		if (THIS->IsClient()) {
			THIS->MoveZoneInstanceRaid(instance_id);
		} else {
			if (THIS->IsMerc()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneInstanceRaid) attempted to process a type Merc reference");
			}
#ifdef BOTS
			else if (THIS->IsBot()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneInstanceRaid) attempted to process a type Bot reference");
			}
#endif
			else if (THIS->IsNPC()) {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneInstanceRaid) attempted to process a type NPC reference");
			}
			else {
				LogDebug("[CLIENT] Perl(XS_Client_MoveZoneInstanceRaid) attempted to process an Unknown type reference");
			}

			Perl_croak(aTHX_ "THIS is not of type Client");
		}

	}
	XSRETURN_EMPTY;
}

XS(XS_Client_ChangeLastName); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_ChangeLastName) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::ChangeLastName(THIS, string last_name)"); // @categories Account and Character
	{
		Client *THIS;
		char   *in_lastname = (char *) SvPV_nolen(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->ChangeLastName(in_lastname);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetFactionLevel); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetFactionLevel) {
	dXSARGS;
	if (items != 8)
		Perl_croak(aTHX_ "Usage: Client::GetFactionLevel(THIS, uint32 character_id, uint32 npc_id, uint32 player_race_id, uint32 player_class_id, uint32 player_deity_id, uint32 player_faction_id, Mob*)"); // @categories Faction
	{
		Client *THIS;
		FACTION_VALUE RETVAL;
		dXSTARG;
		uint32        char_id  = (uint32) SvUV(ST(1));
		uint32        npc_id   = (uint32) SvUV(ST(2));
		uint32        p_race   = (uint32) SvUV(ST(3));
		uint32        p_class  = (uint32) SvUV(ST(4));
		uint32        p_deity  = (uint32) SvUV(ST(5));
		int32         pFaction = (int32) SvIV(ST(6));
		Mob *tnpc;
		VALIDATE_THIS_IS_CLIENT;
		if (sv_derived_from(ST(7), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(7)));
			tnpc = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "tnpc is not of type Mob");
		if (tnpc == nullptr)
			Perl_croak(aTHX_ "tnpc is nullptr, avoiding crash.");

		RETVAL = THIS->GetFactionLevel(char_id, npc_id, p_race, p_class, p_deity, pFaction, tnpc);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_SetFactionLevel); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetFactionLevel) {
	dXSARGS;
	if (items != 6)
		Perl_croak(aTHX_ "Usage: Client::SetFactionLevel(THIS, uint32 character_id, uint32 npc_id, uint8 character_class, uint8 character_race, uint8 character_deity)"); // @categories Faction
	{
		Client *THIS;
		uint32 char_id    = (uint32) SvUV(ST(1));
		uint32 npc_id     = (uint32) SvUV(ST(2));
		uint8  char_class = (uint8) SvUV(ST(3));
		uint8  char_race  = (uint8) SvUV(ST(4));
		uint8  char_deity = (uint8) SvUV(ST(5));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetFactionLevel(char_id, npc_id, char_class, char_race, char_deity);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetFactionLevel2); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetFactionLevel2) {
	dXSARGS;
	if (items < 7 || items > 8)
		Perl_croak(aTHX_ "Usage: Client::SetFactionLevel2(THIS, uint32 character_id, int32 faction_id, uint8 character_class, uint8 character_race, uint8 character_deity, int32 value, uint8 temp)"); // @categories Faction
	{
		Client *THIS;
		uint32 char_id    = (uint32) SvUV(ST(1));
		int32  faction_id = (int32) SvIV(ST(2));
		uint8  char_class = (uint8) SvUV(ST(3));
		uint8  char_race  = (uint8) SvUV(ST(4));
		uint8  char_deity = (uint8) SvUV(ST(5));
		int32  value      = (int32) SvIV(ST(6));
		uint8  temp;
		VALIDATE_THIS_IS_CLIENT;
		if (items == 7)
			temp = 0;
		else {
			temp = (uint8) SvUV(ST(7));
		}

		THIS->SetFactionLevel2(char_id, faction_id, char_class, char_race, char_deity, value, temp);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetRawItemAC); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetRawItemAC) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetRawItemAC(THIS)"); // @categories Inventory and Items
	{
		Client *THIS;
		int16 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetRawItemAC();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_AccountID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_AccountID) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::AccountID(THIS)"); // @categories Account and Character
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->AccountID();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_AccountName); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_AccountName) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::AccountName(THIS)"); // @categories Account and Character
	{
		Client     *THIS;
		Const_char *RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->AccountName();
		sv_setpv(TARG, RETVAL);
		XSprePUSH;
		PUSHTARG;
	}
	XSRETURN(1);
}

XS(XS_Client_Admin); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_Admin) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::Admin(THIS)"); // @categories Account and Character
	{
		Client *THIS;
		int16 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->Admin();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_CharacterID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_CharacterID) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::CharacterID(THIS)"); // @categories Account and Character
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->CharacterID();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_UpdateAdmin); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_UpdateAdmin) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Client::UpdateAdmin(THIS, bool from_db = true)"); // @categories Account and Character
	{
		Client *THIS;
		bool iFromDB;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 2)
			iFromDB = true;
		else {
			iFromDB = (bool) SvTRUE(ST(1));
		}

		THIS->UpdateAdmin(iFromDB);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_UpdateWho); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_UpdateWho) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Client::UpdateWho(THIS, uint8 remove = 0)"); // @categories Script Utility
	{
		Client *THIS;
		uint8  remove;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 2)
			remove = 0;
		else {
			remove = (uint8) SvUV(ST(1));
		}

		THIS->UpdateWho(remove);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GuildRank); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GuildRank) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GuildRank(THIS)"); // @categories Account and Character, Guild
	{
		Client *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GuildRank();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GuildID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GuildID) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GuildID(THIS)"); // @categories Account and Character, Guild
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GuildID();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetFace); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetFace) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetFace(THIS)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetFace();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_TakeMoneyFromPP); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_TakeMoneyFromPP) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Client::TakeMoneyFromPP(THIS, uint32 copper, [bool update_client = false])"); // @categories Currency and Points
	{
		Client *THIS;
		bool has_money;
		bool update_client = false;
		uint32 copper = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;

		if (items == 3) {
			update_client = (bool) SvTRUE(ST(2));
		}

		has_money = THIS->TakeMoneyFromPP(copper, update_client);
		ST(0) = boolSV(has_money);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_AddMoneyToPP); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_AddMoneyToPP) {
	dXSARGS;
	if (items < 5 || items > 6)
		Perl_croak(aTHX_ "Usage: Client::AddMoneyToPP(THIS, uint32 copper, uint32 silver, uint32 gold, uint32 platinum, [bool update_client = false])"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 copper = (uint32) SvUV(ST(1));
		uint32 silver = (uint32) SvUV(ST(2));
		uint32 gold = (uint32) SvUV(ST(3));
		uint32 platinum = (uint32) SvUV(ST(4));
		bool update_client = false;
		VALIDATE_THIS_IS_CLIENT;

		if (items == 6) {
			update_client = (bool) SvTRUE(ST(5));
		}

		THIS->AddMoneyToPP(copper, silver, gold, platinum, update_client);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_TGB); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_TGB) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::TGB(THIS)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->TGB();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_GetSkillPoints); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetSkillPoints) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetSkillPoints(THIS)"); // @categories Skills and Recipes
	{
		Client *THIS;
		uint16 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetSkillPoints();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_SetSkillPoints); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetSkillPoints) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetSkillPoints(THIS, inp)"); // @categories Skills and Recipes
	{
		Client *THIS;
		int inp = (int) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetSkillPoints(inp);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_IncreaseSkill); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_IncreaseSkill) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Client::IncreaseSkill(THIS, int skill_id, int value = 1)"); // @categories Skills and Recipes
	{
		Client *THIS;
		int skill_id = (int) SvIV(ST(1));
		int value;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 3)
			value = 1;
		else {
			value = (int) SvIV(ST(2));
		}

		THIS->IncreaseSkill(skill_id, value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_IncreaseLanguageSkill); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_IncreaseLanguageSkill) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Client::IncreaseLanguageSkill(THIS, int skill_id, int value = 1)"); // @categories Skills and Recipes
	{
		Client *THIS;
		int skill_id = (int) SvIV(ST(1));
		int value;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 3)
			value = 1;
		else {
			value = (int) SvIV(ST(2));
		}

		THIS->IncreaseLanguageSkill(skill_id, value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetRawSkill); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetRawSkill) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetRawSkill(THIS, int skill_id)"); // @categories Skills and Recipes
	{
		Client *THIS;
		uint32                   RETVAL;
		dXSTARG;
		EQ::skills::SkillType skill_id = (EQ::skills::SkillType) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetRawSkill(skill_id);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_HasSkill); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_HasSkill) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::HasSkill(THIS, int skill_id)"); // @categories Skills and Recipes
	{
		Client *THIS;
		bool                     RETVAL;
		EQ::skills::SkillType skill_id = (EQ::skills::SkillType) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->HasSkill(skill_id);
		ST(0)                             = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_CanHaveSkill); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_CanHaveSkill) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::CanHaveSkill(THIS, int skill_id)"); // @categories Skills and Recipes
	{
		Client *THIS;
		bool                     RETVAL;
		EQ::skills::SkillType skill_id = (EQ::skills::SkillType) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->CanHaveSkill(skill_id);
		ST(0)                             = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_SetSkill); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetSkill) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::SetSkill(THIS, int skill_id, uint16 value)"); // @categories Skills and Recipes
	{
		Client *THIS;
		EQ::skills::SkillType skill_num = (EQ::skills::SkillType) SvUV(ST(1));
		uint16                   value     = (uint16) SvUV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetSkill(skill_num, value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_AddSkill); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_AddSkill) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::AddSkill(THIS, int skill_id, uint16 value)"); // @categories Skills and Recipes
	{
		Client                   *THIS;
		EQ::skills::SkillType skillid = (EQ::skills::SkillType) SvUV(ST(1));
		uint16                   value   = (uint16) SvUV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->AddSkill(skillid, value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_CheckSpecializeIncrease); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_CheckSpecializeIncrease) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::CheckSpecializeIncrease(THIS, uint16 spell_id)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		uint16 spell_id = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->CheckSpecializeIncrease(spell_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_CheckIncreaseSkill); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_CheckIncreaseSkill) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Client::CheckIncreaseSkill(THIS, int skill_id, int chance_modifier = 0)"); // @categories Skills and Recipes
	{
		Client *THIS;
		bool                     RETVAL;
		EQ::skills::SkillType skillid = (EQ::skills::SkillType) SvUV(ST(1));
		int                      chancemodi;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 3)
			chancemodi = 0;
		else {
			chancemodi = (int) SvIV(ST(2));
		}

		RETVAL = THIS->CheckIncreaseSkill(skillid, nullptr, chancemodi);
		ST(0)                            = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_SetLanguageSkill); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetLanguageSkill) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::SetLanguageSkill(THIS, int language_id, int value)"); // @categories Account and Character, Skills and Recipes, Stats and Attributes
	{
		Client *THIS;
		int    langid = (int) SvIV(ST(1));
		int    value  = (int) SvIV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetLanguageSkill(langid, value);
	}
	XSRETURN_EMPTY;

}

XS(XS_Client_MaxSkill); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_MaxSkill) {
	dXSARGS;
	if (items < 2 || items > 4)
		Perl_croak(aTHX_ "Usage: Client::MaxSkill(THIS, uint16 skill_id, uint16 class_id, uint16 level)"); // @categories Skills and Recipes
	{
		Client                   *THIS;
		uint16                   RETVAL;
		EQ::skills::SkillType skillid = (EQ::skills::SkillType) SvUV(ST(1));
		uint16                   class_  = 0;
		uint16                   level   = 0;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		if (items > 2)
			class_ = (uint16) SvUV(ST(2));
		else
			class_ = THIS->GetClass();

		if (items > 3)
			level = (uint16) SvUV(ST(3));
		else
			level = THIS->GetLevel();

		RETVAL = THIS->MaxSkill(skillid, class_, level);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GMKill); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GMKill) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GMKill(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->GMKill();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_IsMedding); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_IsMedding) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::IsMedding(THIS)"); // @categories Account and Character
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->IsMedding();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_GetDuelTarget); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetDuelTarget) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetDuelTarget(THIS)"); // @categories Account and Character, Script Utility
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetDuelTarget();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_IsDueling); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_IsDueling) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::IsDueling(THIS)"); // @categories Account and Character
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->IsDueling();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_SetDuelTarget); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetDuelTarget) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetDuelTarget(THIS, set_id)"); // @categories Account and Character
	{
		Client *THIS;
		uint32 set_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetDuelTarget(set_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetDueling); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetDueling) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetDueling(THIS, duel)"); // @categories Account and Character, Script Utility
	{
		Client *THIS;
		bool duel = (bool) SvTRUE(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetDueling(duel);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_ResetAA); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_ResetAA) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::ResetAA(THIS)"); // @categories Alternative Advancement
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->ResetAA();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_MemSpell); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_MemSpell) {
	dXSARGS;
	if (items < 3 || items > 4)
		Perl_croak(aTHX_ "Usage: Client::MemSpell(THIS, uint16 spell_id, int slot, [bool update_client = true])"); // @categories Spells and Disciplines
	{
		Client *THIS;
		uint16 spell_id = (uint16) SvUV(ST(1));
		int    slot     = (int) SvIV(ST(2));
		bool   update_client;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 4)
			update_client = true;
		else {
			update_client = (bool) SvTRUE(ST(3));
		}

		THIS->MemSpell(spell_id, slot, update_client);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_UnmemSpell); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_UnmemSpell) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Client::UnmemSpell(THIS, int slot, [bool update_client = true])"); // @categories Spells and Disciplines
	{
		Client *THIS;
		int    slot = (int) SvIV(ST(1));
		bool   update_client;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 3)
			update_client = true;
		else {
			update_client = (bool) SvTRUE(ST(2));
		}

		THIS->UnmemSpell(slot, update_client);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_UnmemSpellBySpellID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_UnmemSpellBySpellID) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::UnmemSpellBySpellID(THIS, int32 spell_id)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		int32  spell_id = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->UnmemSpellBySpellID(spell_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_UnmemSpellAll); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_UnmemSpellAll) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Client::UnmemSpellAll(THIS, [bool update_client = true])"); // @categories Spells and Disciplines
	{
		Client *THIS;
		bool   update_client;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 2)
			update_client = true;
		else {
			update_client = (bool) SvTRUE(ST(1));
		}

		THIS->UnmemSpellAll(update_client);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_FindEmptyMemSlot); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_FindEmptyMemSlot) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::FindEmptyMemSlot(THIS)"); // @categories Account and Character, Spells and Disciplines
	{
		Client *THIS;
		int RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->FindEmptyMemSlot();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_FindMemmedSpellBySlot); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_FindMemmedSpellBySlot) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::FindMemmedSpellBySlot(THIS, int slot)"); // @categories Account and Character, Spells and Disciplines
	{
		Client *THIS;
		uint16 RETVAL;
		dXSTARG;
		int slot = SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->FindMemmedSpellBySlot(slot);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_FindMemmedSpellBySpellID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_FindMemmedSpellBySpellID) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::FindMemmedSpellBySpellID(THIS, uint16 spell_id)"); // @categories Account and Character, Spells and Disciplines
	{
		Client *THIS;
		int RETVAL;
		dXSTARG;
		uint16 spell_id = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->FindMemmedSpellBySpellID(spell_id);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_MemmedCount); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_MemmedCount) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::MemmedCount(THIS)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		uint32  RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->MemmedCount();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_ScribeSpell); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_ScribeSpell) {
	dXSARGS;
	if (items < 3 || items > 4)
		Perl_croak(aTHX_ "Usage: Client::ScribeSpell(THIS, uint16 spell_id, int slot, [bool update_client = true])"); // @categories Spells and Disciplines
	{
		Client *THIS;
		uint16 spell_id = (uint16) SvUV(ST(1));
		int    slot     = (int) SvIV(ST(2));
		bool   update_client;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 4)
			update_client = true;
		else {
			update_client = (bool) SvTRUE(ST(3));
		}

		THIS->ScribeSpell(spell_id, slot, update_client);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_UnscribeSpell); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_UnscribeSpell) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Client::UnscribeSpell(THIS, int slot, [bool update_client = true])"); // @categories Spells and Disciplines
	{
		Client *THIS;
		int    slot = (int) SvIV(ST(1));
		bool   update_client;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 3)
			update_client = true;
		else {
			update_client = (bool) SvTRUE(ST(2));
		}

		THIS->UnscribeSpell(slot, update_client);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_UnscribeSpellAll); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_UnscribeSpellAll) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Client::UnscribeSpellAll(THIS, [bool update_client = true])");
	{
		Client *THIS;
		bool update_client;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 2)
			update_client = true;
		else {
			update_client = (bool) SvTRUE(ST(1));
		}

		THIS->UnscribeSpellAll(update_client);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_TrainDiscBySpellID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_TrainDiscBySpellID) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::TrainDiscBySpellID(THIS, int32 spell_id)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		int32 spell_id = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->TrainDiscBySpellID(spell_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetDiscSlotBySpellID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetDiscSlotBySpellID) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetDiscSlotBySpellID(THIS, int32 spell_id)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		int   RETVAL;
		int32 spell_id = (int32) SvIV(ST(1));
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetDiscSlotBySpellID(spell_id);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_UntrainDisc); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_UntrainDisc) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Client::UntrainDisc(THIS, int slot, [bool update_client = true])"); // @categories Spells and Disciplines
	{
		Client *THIS;
		int    slot = (int) SvIV(ST(1));
		bool   update_client;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 3)
			update_client = true;
		else {
			update_client = (bool) SvTRUE(ST(2));
		}

		THIS->UntrainDisc(slot, update_client);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_UntrainDiscAll); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_UntrainDiscAll) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Client::UntrainDiscAll(THIS, [update_client = true])"); // @categories Spells and Disciplines
	{
		Client *THIS;
		bool   update_client;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 2)
			update_client = true;
		else {
			update_client = (bool) SvTRUE(ST(1));
		}

		THIS->UntrainDiscAll(update_client);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_IsStanding); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_IsStanding)
{
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::IsStanding(THIS)"); // @categories Account and Character
	{
		Client *		THIS;
		bool		RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->IsStanding();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_Sit);
XS(XS_Client_Sit) {
    dXSARGS;
    if (items != 1)
        Perl_croak(aTHX_ "Usage: Client::Sit(THIS)");
    {
        Client *THIS;
        VALIDATE_THIS_IS_CLIENT;
        THIS->Sit();
    }
    XSRETURN_EMPTY;
}

XS(XS_Client_IsSitting); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_IsSitting) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::IsSitting(THIS)"); // @categories Account and Character
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->IsSitting();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_IsCrouching); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_IsCrouching)
{
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::IsCrouching(THIS)"); // @categories Account and Character
	{
		Client *		THIS;
		bool		RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->IsCrouching();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_IsBecomeNPC); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_IsBecomeNPC) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::IsBecomeNPC(THIS)"); // @categories Account and Character
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->IsBecomeNPC();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_GetBecomeNPCLevel); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetBecomeNPCLevel) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetBecomeNPCLevel(THIS)"); // @categories Experience and Level
	{
		Client *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetBecomeNPCLevel();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_SetBecomeNPC); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetBecomeNPC) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetBecomeNPC(THIS, flag)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		bool flag = (bool) SvTRUE(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetBecomeNPC(flag);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetBecomeNPCLevel); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetBecomeNPCLevel) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetBecomeNPCLevel(THIS, level)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint8 level = (uint8) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetBecomeNPCLevel(level);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetFeigned); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetFeigned) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetFeigned(THIS, in_feigned)"); // @categories Script Utility
	{
		Client *THIS;
		bool in_feigned = (bool) SvTRUE(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetFeigned(in_feigned);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetFeigned); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetFeigned) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetFeigned(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetFeigned();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_AutoSplitEnabled); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_AutoSplitEnabled) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::AutoSplitEnabled(THIS)"); // @categories Currency and Points
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->AutoSplitEnabled();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_SetHorseId); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetHorseId) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetHorseId(THIS, horseid_in)"); // @categories Script Utility
	{
		Client *THIS;
		uint16 horseid_in = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetHorseId(horseid_in);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetHorseId); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetHorseId) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetHorseId(THIS)"); // @categories Account and Character, Script Utility
	{
		Client *THIS;
		uint16 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetHorseId();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_NukeItem); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_NukeItem) {
	dXSARGS;
	if (items != 3 && items != 2)
		Perl_croak(aTHX_ "Usage: Client::NukeItem(THIS, uint32 item_id, [uint8 slot_to_check])"); // @categories Inventory and Items
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		uint32 itemnum = (uint32) SvUV(ST(1));
		uint8  where_to_check;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 3) {
			where_to_check = 0xFF;
		}
		if (items == 3) {
			where_to_check = (uint8) SvUV(ST(2));
		}

		RETVAL = THIS->NukeItem(itemnum, where_to_check);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_SetTint); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetTint) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::SetTint(THIS, int16 slot_id, uint32 color)"); // @categories Inventory and Items
	{
		Client *THIS;
		int16  slot_id = (int16) SvIV(ST(1));
		uint32 color   = (uint32) SvUV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetTint(slot_id, color);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetMaterial); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetMaterial) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::SetMaterial(THIS, int16 slot_id, uint32 item_id)"); // @categories Inventory and Items
	{
		Client *THIS;
		int16  slot_id = (int16) SvIV(ST(1));
		uint32 item_id = (uint32) SvUV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetMaterial(slot_id, item_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_Undye); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_Undye) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::Undye(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->Undye();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetItemIDAt); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetItemIDAt) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetItemIDAt(THIS, int16 slot_id)"); // @categories Inventory and Items
	{
		Client *THIS;
		int32 RETVAL;
		dXSTARG;
		int16 slot_id = (int16) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetItemIDAt(slot_id);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetAugmentIDAt); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetAugmentIDAt) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::GetAugmentIDAt(THIS, int16 slot_id, int16 aug_slot)"); // @categories Inventory and Items
	{
		Client *THIS;
		int32 RETVAL;
		dXSTARG;
		int16 slot_id = (int16) SvIV(ST(1));
		int16 augslot = (uint8) SvIV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetAugmentIDAt(slot_id, augslot);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_DeleteItemInInventory); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_DeleteItemInInventory) {
	dXSARGS;
	if (items < 2 || items > 4)
		Perl_croak(aTHX_ "Usage: Client::DeleteItemInInventory(THIS, int16 slot_id, [int16 quantity = 0], [bool client_update = false])"); // @categories Inventory and Items
	{
		Client *THIS;
		int16  slot_id = (int16) SvIV(ST(1));
		int16   quantity;
		bool   client_update;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 3)
			quantity = 0;
		else {
			quantity = (int16) SvIV(ST(2));
		}

		if (items < 4)
			client_update = false;
		else {
			client_update = (bool) SvTRUE(ST(3));
		}

		THIS->DeleteItemInInventory(slot_id, quantity, client_update);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SummonItem); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SummonItem) {
	dXSARGS;
	if (items < 2 || items > 10)
		Perl_croak(aTHX_ "Usage: Client::SummonItem(THIS, uint32 item_id, [int16 charges = -1], [bool attune = false], [uint32 aug1 = 0], [uint32 aug2 = 0], [uint32 aug3 = 0], [uint32 aug4 = 0], [uint32 aug5 = 0], [uint16 slot_id = cursor])"); // @categories Inventory and Items, Script Utility
	{
		Client *THIS;
		uint32 item_id = (uint32) SvUV(ST(1));
		int16  charges = -1;
		bool   attune  = false;
		uint32 aug1    = 0;
		uint32 aug2    = 0;
		uint32 aug3    = 0;
		uint32 aug4    = 0;
		uint32 aug5    = 0;
		uint16 slot_id = EQ::invslot::slotCursor;
		VALIDATE_THIS_IS_CLIENT;
		if (items > 2) {
			charges = (int16) SvIV(ST(2));
		}
		if (items > 3) {
			attune = (bool) SvTRUE(ST(3));
		}
		if (items > 4) {
			aug1 = (uint32) SvUV(ST(4));
		}
		if (items > 5) {
			aug2 = (uint32) SvUV(ST(5));
		}
		if (items > 6) {
			aug3 = (uint32) SvUV(ST(6));
		}
		if (items > 7) {
			aug4 = (uint32) SvUV(ST(7));
		}
		if (items > 8) {
			aug5 = (uint32) SvUV(ST(8));
		}
		if (items > 9) {
			slot_id = (uint16) SvUV(ST(9));
		}

		THIS->SummonItem(item_id, charges, aug1, aug2, aug3, aug4, aug5, 0, attune, slot_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetStats); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetStats) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::SetStats(THIS, uint8 type, uint16 increase_val)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint8 type         = (uint8) SvUV(ST(1));
		int16 increase_val = (int16) SvIV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetStats(type, increase_val);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_IncStats); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_IncStats) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::IncStats(THIS, uint8 type, uint16 increase_val)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint8 type         = (uint8) SvUV(ST(1));
		int16 increase_val = (int16) SvIV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->IncStats(type, increase_val);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_DropItem); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_DropItem) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::DropItem(THIS, int16 slot_id)"); // @categories Inventory and Items
	{
		Client *THIS;
		int16 slot_id = (int16) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->DropItem(slot_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_BreakInvis); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_BreakInvis) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::BreakInvis(THIS)"); // @categories Spells and Disciplines, Script Utility
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->BreakInvis();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetGroup); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetGroup) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetGroup(THIS)"); // @categories Account and Character, Group
	{
		Client *THIS;
		Group  *RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetGroup();
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Group", (void *) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_LeaveGroup); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_LeaveGroup) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::LeaveGroup(THIS)"); // @categories Account and Character, Group
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->LeaveGroup();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetRaid); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetRaid) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetRaid(THIS)"); // @categories Account and Character, Raid
	{
		Client *THIS;
		Raid   *RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetRaid();
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Raid", (void *) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_IsGrouped); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_IsGrouped) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::IsGrouped(THIS)"); // @categories Account and Character, Group
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->IsGrouped();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_IsRaidGrouped); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_IsRaidGrouped) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::IsRaidGrouped(THIS)"); // @categories Account and Character, Group, Raid
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->IsRaidGrouped();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_Hungry); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_Hungry) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::Hungry(THIS)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->Hungry();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_Thirsty); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_Thirsty) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::Thirsty(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->Thirsty();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_GetInstrumentMod); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetInstrumentMod) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetInstrumentMod(THIS, uint16 spell_id)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		uint16 RETVAL;
		dXSTARG;
		uint16 spell_id = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetInstrumentMod(spell_id);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_DecreaseByID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_DecreaseByID) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::DecreaseByID(THIS, uint32 type, int16 quantity)"); // @categories Script Utility
	{
		Client *THIS;
		bool   RETVAL;
		uint32 type = (uint32) SvUV(ST(1));
		int16  quantity  = (int16) SvIV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->DecreaseByID(type, quantity);
		ST(0)       = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_SlotConvert2); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SlotConvert2) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SlotConvert2(THIS, uint8 slot)"); // @categories Inventory and Items
	{
		Client *THIS;
		uint8 RETVAL;
		dXSTARG;
		uint8 slot = (uint8) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->SlotConvert2(slot);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_Escape); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_Escape) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::Escape(THIS)"); // @categories Account and Character, Skills and Recipes
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->Escape();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_RemoveNoRent); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_RemoveNoRent) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::RemoveNoRent(THIS)"); // @categories Inventory and Items
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->RemoveNoRent();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GoFish); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GoFish) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GoFish(THIS)"); // @categories Skills and Recipes
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->GoFish();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_ForageItem); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_ForageItem) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::ForageItem(THIS)"); // @categories Skills and Recipes
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->ForageItem();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_CalcPriceMod); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_CalcPriceMod) {
	dXSARGS;
	if (items < 1 || items > 3)
		Perl_croak(aTHX_ "Usage: Client::CalcPriceMod(THIS, Mob*, [bool reverse = false])"); // @categories Currency and Points
	{
		Client *THIS;
		float  RETVAL;
		dXSTARG;
		Mob    *other;
		bool   reverse;
		VALIDATE_THIS_IS_CLIENT;
		if (items < 2)
			other = 0;
		else {
			if (sv_derived_from(ST(1), "Mob")) {
				IV tmp = SvIV((SV *) SvRV(ST(1)));
				other = INT2PTR(Mob *, tmp);
			} else
				Perl_croak(aTHX_ "other is not of type Mob");
			if (other == nullptr)
				Perl_croak(aTHX_ "other is nullptr, avoiding crash.");
		}

		if (items < 3)
			reverse = false;
		else {
			reverse = (bool) SvTRUE(ST(2));
		}

		RETVAL = THIS->CalcPriceMod(other, reverse);
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_ResetTrade); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_ResetTrade) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::ResetTrade(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->ResetTrade();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_UseDiscipline); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_UseDiscipline) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::UseDiscipline(THIS, int32 spell_id, int32 target)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		bool   RETVAL;
		uint32 spell_id = (uint32) SvUV(ST(1));
		uint32 target   = (uint32) SvUV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->UseDiscipline(spell_id, target);
		ST(0)           = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_GetDisciplineTimer); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetDisciplineTimer) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetDisciplineTimer(THIS, uint32 timer_id)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		uint32 timer_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetDisciplineTimer(timer_id);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_ResetDisciplineTimer); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_ResetDisciplineTimer) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::ResetDisciplineTimer(THIS, uint32 timer_id)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		uint32 timer_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->ResetDisciplineTimer(timer_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetCharacterFactionLevel); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetCharacterFactionLevel) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetCharacterFactionLevel(THIS, int32 faction_id)"); // @categories Faction
	{
		Client *THIS;
		int32  RETVAL;
		dXSTARG;
		int32  faction_id = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetCharacterFactionLevel(faction_id);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_SetZoneFlag); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetZoneFlag) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetZoneFlag(THIS, uint32 zone_id)"); // @categories Account and Character, Zones
	{
		Client *THIS;
		uint32 zone_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetZoneFlag(zone_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_ClearZoneFlag); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_ClearZoneFlag) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::ClearZoneFlag(THIS, uint32 zone_id)"); // @categories Script Utility
	{
		Client *THIS;
		uint32 zone_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->ClearZoneFlag(zone_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_HasZoneFlag); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_HasZoneFlag) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::HasZoneFlag(THIS, uint32 zone_id)"); // @categories Account and Character
	{
		Client *THIS;
		bool   RETVAL;
		uint32 zone_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->HasZoneFlag(zone_id);
		ST(0)          = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_SendZoneFlagInfo); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SendZoneFlagInfo) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SendZoneFlagInfo(THIS, Client* to)"); // @categories Account and Character, Zones
	{
		Client *THIS;
		Client *to;
		VALIDATE_THIS_IS_CLIENT;
		if (sv_derived_from(ST(1), "Client")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			to = INT2PTR(Client *, tmp);
		} else
			Perl_croak(aTHX_ "to is not of type Client");
		if (to == nullptr)
			Perl_croak(aTHX_ "to is nullptr, avoiding crash.");

		THIS->SendZoneFlagInfo(to);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_LoadZoneFlags); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_LoadZoneFlags) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::LoadZoneFlags(THIS)"); // @categories Zones
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->LoadZoneFlags();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetAATitle); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetAATitle) {
	dXSARGS;
	if ((items < 2) || (items > 3))
		Perl_croak(aTHX_ "Usage: Client::SetAATitle(THIS, string text, [bool save = false])"); // @categories Alternative Advancement
	{
		Client *THIS;
		char   *txt = (char *) SvPV_nolen(ST(1));
		bool SaveTitle = false;
		VALIDATE_THIS_IS_CLIENT;
		if (strlen(txt) > 31)
			Perl_croak(aTHX_ "Title must be 31 characters or less");

		if (items == 3)
			SaveTitle = (SvIV(ST(2)) != 0);

		if (!SaveTitle)
			THIS->SetAATitle(txt);
		else
			title_manager.CreateNewPlayerTitle(THIS, txt);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetClientVersion); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetClientVersion) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetClientVersion(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = static_cast<unsigned int>(THIS->ClientVersion());
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetClientVersionBit); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetClientVersionBit) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetClientVersionBit(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->ClientVersionBit();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_SetTitleSuffix);
XS(XS_Client_SetTitleSuffix) {
	dXSARGS;
	if ((items < 2) || (items > 3))
		Perl_croak(aTHX_ "Usage: Client::SetTitleSuffix(THIS, string text, [bool save = false])"); // @categories Account and Character
	{
		Client *THIS;
		char   *txt = (char *) SvPV_nolen(ST(1));
		bool SaveSuffix = false;
		VALIDATE_THIS_IS_CLIENT;
		if (strlen(txt) > 31)
			Perl_croak(aTHX_ "Title must be 31 characters or less");

		if (items == 3)
			SaveSuffix = (SvIV(ST(2)) != 0);

		if (!SaveSuffix)
			THIS->SetTitleSuffix(txt);
		else
			title_manager.CreateNewPlayerSuffix(THIS, txt);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetAAPoints);
XS(XS_Client_SetAAPoints) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetAAPoints(THIS, uint32 points)"); // @categories Alternative Advancement
	{
		Client *THIS;
		uint32 points = SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetAAPoints(points);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetAAPoints);
XS(XS_Client_GetAAPoints) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetAAPoints(THIS)"); // @categories Alternative Advancement, Experience and Level
	dXSTARG;
	{
		Client *THIS;
		uint32 RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetAAPoints();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetSpentAA);
XS(XS_Client_GetSpentAA) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetSpentAA(THIS)"); // @categories Alternative Advancement
	dXSTARG;
	{
		Client *THIS;
		uint32 RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetSpentAA();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_AddAAPoints);
XS(XS_Client_AddAAPoints) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::AddAAPoints(THIS, uint32 points)"); // @categories Alternative Advancement
	{
		Client *THIS;
		uint32 points = SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->AddAAPoints(points);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_RefundAA);
XS(XS_Client_RefundAA) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::RefundAA(THIS)"); // @categories Alternative Advancement
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->RefundAA();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetModCharacterFactionLevel); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetModCharacterFactionLevel) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetModCharacterFactionLevel(THIS, int32 faction_id)"); // @categories Faction
	{
		Client *THIS;
		int32 RETVAL;
		dXSTARG;
		int32 faction_id = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetModCharacterFactionLevel(faction_id);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetLDoNWins); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetLDoNWins) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetLDoNWins(THIS)"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetLDoNWins();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetLDoNLosses); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetLDoNLosses) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetLDoNLosses(THIS)"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetLDoNLosses();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetLDoNWinsTheme); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetLDoNWinsTheme) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetLDoNWinsTheme(THIS, int32 theme)"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		int32  theme_out = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetLDoNWinsTheme(theme_out);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetLDoNLossesTheme); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetLDoNLossesTheme) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetLDoNLossesTheme(THIS, int32 theme)"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		int32  theme_out = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetLDoNLossesTheme(theme_out);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetItemAt); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetItemAt) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetItemAt(THIS, uint32 slot)"); // @categories Inventory and Items
	{
		Client              *THIS;
		EQ::ItemInstance *RETVAL;
		uint32 slot = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetInv().GetItem(slot);
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "QuestItem", (void *) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetAugmentAt); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetAugmentAt) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::GetAugmentAt(THIS, uint32 slot, uint32 aug_slot)"); // @categories Inventory and Items
	{
		Client              *THIS;
		EQ::ItemInstance *RETVAL;
		uint32 slot     = (int32) SvIV(ST(1));
		uint32 aug_slot = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		EQ::ItemInstance *inst = THIS->GetInv().GetItem(slot);
		if (inst) {
			RETVAL = inst->GetAugment(aug_slot);
		} else {
			RETVAL = nullptr;
		}

		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "QuestItem", (void *) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetStartZone);
XS(XS_Client_GetStartZone) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetStartZone(THIS)"); // @categories Account and Character
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetStartZone();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_SetStartZone);
XS(XS_Client_SetStartZone) {
	dXSARGS;
	if (items != 2 && items != 5 && items != 6)
		Perl_croak(aTHX_ "Usage: Client::SetStartZone(THIS, uint32 zone_id, [float x = 0, float y = 0, float z = 0, [float heading = 0]])");
	{
		Client *THIS;
		uint32 zoneid = (uint32) SvUV(ST(1));
		float  x = 0.0f, y = 0.0f, z = 0.0f, heading = 0.0f;
		VALIDATE_THIS_IS_CLIENT;
		if (items == 5) {
			x = (float) SvNV(ST(2));
			y = (float) SvNV(ST(3));
			z = (float) SvNV(ST(4));
		}
		if (items == 6)
			heading = (float) SvNV(ST(5));

		THIS->SetStartZone(zoneid, x, y, z, heading);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_KeyRingAdd);
XS(XS_Client_KeyRingAdd) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::KeyRingAdd(THIS, uint32 item_id)"); // @categories Account and Character, Inventory and Items
	{
		Client *THIS;
		uint32 item_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->KeyRingAdd(item_id);;
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_KeyRingCheck);
XS(XS_Client_KeyRingCheck) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::KeyRingCheck(THIS, uint32 item_id)"); // @categories Account and Character, Inventory and Items
	{
		Client *THIS;
		bool   RETVAL;
		uint32 item_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->KeyRingCheck(item_id);;
		ST(0)          = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_AddPVPPoints);
XS(XS_Client_AddPVPPoints) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::AddPVPPoints(THIS, uint32 points)"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 Points = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->AddPVPPoints(Points);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_AddCrystals);
XS(XS_Client_AddCrystals) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::AddCrystals(THIS, uint32 radiant_count, uint32 ebon_count)"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 Radiant = (uint32) SvUV(ST(1));
		uint32 Ebon    = (uint32) SvUV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->AddCrystals(Radiant, Ebon);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetEbonCrystals);
XS(XS_Client_SetEbonCrystals) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetEbonCrystals(THIS, uint32 value)");
	{
		Client *THIS;
		uint32 value = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetEbonCrystals(value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetRadiantCrystals);
XS(XS_Client_SetRadiantCrystals) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetRadiantCrystals(THIS, uint32 value)");
	{
		Client *THIS;
		uint32 value = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetRadiantCrystals(value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetPVPPoints); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetPVPPoints) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetPVPPoints(THIS)"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetPVPPoints();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetRadiantCrystals); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetRadiantCrystals) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetRadiantCrystals(THIS)"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetRadiantCrystals();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetEbonCrystals); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetEbonCrystals) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetEbonCrystals(THIS)"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetEbonCrystals();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_ReadBook); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_ReadBook) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::ReadBook(THIS, char* book_test, uint8 type)"); // @categories Script Utility
	{
		Client *THIS;
		char   *in_txt = (char *) SvPV_nolen(ST(1));
		uint8 type = (uint8) SvUV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->QuestReadBook(in_txt, type);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetGMStatus); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetGMStatus) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetGMStatus(THIS, int newStatus)"); // @categories Script Utility
	{
		Client *THIS;
		int newStatus = (int)SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetGMStatus(newStatus);
		THIS->UpdateAdmin(true);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_UpdateGroupAAs); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_UpdateGroupAAs) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::UpdateGroupAAs(THIS, int32 points, uint32 type)"); // @categories Alternative Advancement, Group
	{
		Client *THIS;
		int32  points = (int32) SvIV(ST(1));
		uint32 type   = (uint32) SvUV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->UpdateGroupAAs(points, type);
	}
	XSRETURN(1);
}

XS(XS_Client_GetGroupPoints); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetGroupPoints) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetGroupPoints(THIS)"); // @categories Account and Character, Group
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetGroupPoints();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetRaidPoints); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetRaidPoints) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetRaidPoints(THIS)"); // @categories Account and Character, Raid
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetRaidPoints();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_LearnRecipe);
XS(XS_Client_LearnRecipe) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::LearnRecipe(THIS, uint32 recipe_id)"); // @categories Skills and Recipes
	{
		Client *THIS;
		uint32 recipe_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->LearnRecipe(recipe_id);;
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetEndurance); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetEndurance) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetEndurance(THIS)"); // @categories Stats and Attributes
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetEndurance();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetMaxEndurance); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetMaxEndurance) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetMaxEndurance(THIS)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetMaxEndurance();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetEnduranceRatio); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetEnduranceRatio) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetEnduranceRatio(THIS)"); // @categories Stats and Attributes
	{
		Client *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetEndurancePercent();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_SetEndurance);
XS(XS_Client_SetEndurance) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetEndurance(THIS, Endurance)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		int32 Endurance = (int32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetEndurance(Endurance);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SendOPTranslocateConfirm);
XS(XS_Client_SendOPTranslocateConfirm) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::SendOPTranslocateConfirm(THIS, Mob* caster, int32 spell_id)"); // @categories Script Utility
	{
		Client *THIS;
		Mob    *caster = nullptr;
		int32 spell_id = (int32) SvUV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			caster = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "caster is not of type Mob");
		if (caster == nullptr)
			Perl_croak(aTHX_ "caster is nullptr, avoiding crash.");

		THIS->SendOPTranslocateConfirm(caster, spell_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_NPCSpawn); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_NPCSpawn) {
	dXSARGS;
	if (items < 3 || items > 4)
		Perl_croak(aTHX_ "Usage: Client::NPCSpawn(THIS, NPC*, string option, uint32 respawn_time=1200)"); // @categories Script Utility, Spawns
	{
		Client     *THIS;
		NPC        *target_npc = nullptr;
		Const_char *option     = (Const_char *) SvPV_nolen(ST(2));
		uint32 respawntime = 1200;
		VALIDATE_THIS_IS_CLIENT;
		if (sv_derived_from(ST(1), "NPC")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			target_npc = INT2PTR(NPC *, tmp);
		} else
			Perl_croak(aTHX_ "THIS is not of type NPC");
		if (target_npc == nullptr)
			Perl_croak(aTHX_ "THIS is nullptr, avoiding crash.");

		if (items > 3)
			respawntime = (uint32) SvUV(ST(3));

		THIS->NPCSpawn(target_npc, option, respawntime);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetIP); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetIP) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetIP(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetIP();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_AddLevelBasedExp);
XS(XS_Client_AddLevelBasedExp) {
	dXSARGS;
	if (items < 2 || items > 4)
		Perl_croak(aTHX_ "Usage: Client::AddLevelBasedExp(THIS, uint8 exp_percentage, uint8 max_level = 0, bool ignore_mods = false)"); // @categories Experience and Level
	{
		Client *THIS;
		uint8 exp_percentage = (uint8) SvUV(ST(1));
		uint8 max_level      = 0;
		bool ignore_mods	 = false;
		VALIDATE_THIS_IS_CLIENT;
		if (items > 2)
			max_level = (uint8) SvUV(ST(2));

		if (items > 3)
			ignore_mods = (bool) SvTRUE(ST(3));

		THIS->AddLevelBasedExp(exp_percentage, max_level, ignore_mods);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_IncrementAA);
XS(XS_Client_IncrementAA) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::IncrementAA(THIS, uint32 aa_skill_id)"); // @categories Alternative Advancement
	{
		Client *THIS;
		uint32 aaskillid = SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->IncrementAlternateAdvancementRank(aaskillid);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GrantAlternateAdvancementAbility); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GrantAlternateAdvancementAbility) {
	dXSARGS;
	if (items < 3 || items > 4)
		Perl_croak(aTHX_ "Usage: Client::GrantAlternateAdvancementAbility(THIS, int aa_id, int points, [bool ignore_cost = false])"); // @categories Alternative Advancement
	{
		Client *THIS;
		bool RETVAL;
		int  aa_id       = (int) SvIV(ST(1));
		int  points      = (int) SvIV(ST(2));
		bool ignore_cost = false;
		VALIDATE_THIS_IS_CLIENT;
		if (items > 3) {
			ignore_cost = (bool) SvTRUE(ST(3));
		}

		RETVAL = THIS->GrantAlternateAdvancementAbility(aa_id, points, ignore_cost);
		ST(0)            = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_GetAALevel);
XS(XS_Client_GetAALevel) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetAALevel(THIS, uint32 aa_skill_id)"); // @categories Alternative Advancement, Experience and Level
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		uint32 aaskillid = SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetAA(aaskillid);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_MarkCompassLoc);
XS(XS_Client_MarkCompassLoc) {
	dXSARGS;
	if (items != 4)
		Perl_croak(aTHX_ "Usage: Client::MarkCompassLoc(THIS, float x, float y, float z)"); // @categories Adventures and Expeditions
	{
		Client *THIS;
		float x = SvNV(ST(1));
		float y = SvNV(ST(2));
		float z = SvNV(ST(3));
		VALIDATE_THIS_IS_CLIENT;
		THIS->MarkSingleCompassLoc(x, y, z);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_ClearCompassMark);
XS(XS_Client_ClearCompassMark) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::ClearCompassMark(THIS)"); // @categories Adventures and Expeditions
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->MarkSingleCompassLoc(0, 0, 0, 0);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetFreeSpellBookSlot); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetFreeSpellBookSlot) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Client::GetFreeSpellBookSlot(THIS, uint32 start_slot = 0)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		int    RETVAL;
		uint32 start_slot = 0;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		if (items > 1)
			start_slot = SvUV(ST(1));

		RETVAL = THIS->GetNextAvailableSpellBookSlot(start_slot);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetSpellBookSlotBySpellID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetSpellBookSlotBySpellID) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetSpellBookSlotBySpellID(THIS, uint32 spell_id)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		int    RETVAL;
		uint32 spell_id = SvUV(ST(1));
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->FindSpellBookSlotBySpellID(spell_id);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetSpellIDByBookSlot); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetSpellIDByBookSlot) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetSpellIDByBookSlot(THIS, int slot_id)");
	{
		Client* THIS;
		int    RETVAL;
		int	   slot_id = SvUV(ST(1));
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetSpellIDByBookSlot(slot_id);
		XSprePUSH;
		PUSHi((IV)RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_UpdateTaskActivity); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_UpdateTaskActivity) {
	dXSARGS;
	if (items < 4)
		Perl_croak(aTHX_ "Usage: Client::UpdateTaskActivity(THIS, int task_id, int activity_id, int count, [bool ignore_quest_update = false])"); // @categories Tasks and Activities
	{
		bool ignore_quest_update = false;

		Client *THIS;

		int TaskID     = (int) SvIV(ST(1));
		int ActivityID = (int) SvIV(ST(2));
		int Count      = (int) SvUV(ST(3));

		if (items == 5) {
			ignore_quest_update = (bool) SvTRUE(ST(4));
		}
		VALIDATE_THIS_IS_CLIENT;
		THIS->UpdateTaskActivity(TaskID, ActivityID, Count, ignore_quest_update);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetTaskActivityDoneCount); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetTaskActivityDoneCount) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::GetTaskActivityDoneCount(THIS, int task_id, int activity_id)"); // @categories Tasks and Activities
	{
		Client *THIS;
		int RETVAL;
		int TaskID     = (int) SvIV(ST(1));
		int ActivityID = (int) SvIV(ST(2));
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;

		RETVAL = THIS->GetTaskActivityDoneCountFromTaskID(TaskID, ActivityID);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_AssignTask); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_AssignTask) {
	dXSARGS;
	if (items != 3 && items != 4)
		Perl_croak(aTHX_ "Usage: Client::AssignTask(THIS, int task_id, int npc_id, [bool enforce_level_requirement = false])"); // @categories Tasks and Activities
	{
		Client *THIS;
		int  TaskID                    = (int) SvIV(ST(1));
		int  NPCID                     = (int) SvIV(ST(2));
		bool enforce_level_requirement = false;
		if (items == 4) {
			if ((int) SvIV(ST(3)) == 1) {
				enforce_level_requirement = true;
			}
		}
		VALIDATE_THIS_IS_CLIENT;
		THIS->AssignTask(TaskID, NPCID, enforce_level_requirement);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_FailTask); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_FailTask) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::FailTask(THIS, int task_id)"); // @categories Tasks and Activities
	{
		Client *THIS;
		int TaskID = (int) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->FailTask(TaskID);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_IsTaskCompleted); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_IsTaskCompleted) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::IsTaskCompleted(THIS, int task_id)"); // @categories Tasks and Activities
	{
		Client *THIS;
		int RETVAL;
		int TaskID = (int) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->IsTaskCompleted(TaskID);
		ST(0)      = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_IsTaskActive); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_IsTaskActive) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::IsTaskActive(THIS, int task_id)"); // @categories Tasks and Activities
	{
		Client *THIS;
		bool RETVAL;
		int  TaskID = (int) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->IsTaskActive(TaskID);
		ST(0)       = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_IsTaskActivityActive); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_IsTaskActivityActive) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::IsTaskActivityActive(THIS, int task_id, int activity_id)"); // @categories Tasks and Activities
	{
		Client *THIS;
		bool RETVAL;
		int  TaskID     = (int) SvIV(ST(1));
		int  ActivityID = (int) SvIV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->IsTaskActivityActive(TaskID, ActivityID);
		ST(0)           = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_GetCorpseCount); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetCorpseCount) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetCorpseCount(THIS)"); // @categories Account and Character, Corpse
	{
		Client *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetCorpseCount();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetCorpseID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetCorpseID) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetCorpseID(THIS, uint8 corpse)"); // @categories Account and Character, Corpse
	{
		Client *THIS;
		uint8  corpse = (uint8) SvIV(ST(1));
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetCorpseID(corpse);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetCorpseItemAt); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetCorpseItemAt) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::GetCorpseItemAt(THIS, uint32 corpse_id, uint16 slot_id)"); // @categories Inventory and Items, Corpse
	{
		Client *THIS;
		uint32 corpse_id = (uint32) SvIV(ST(1));
		uint16 slotid    = (uint16) SvIV(ST(2));
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetCorpseItemAt(corpse_id, slotid);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_AssignToInstance); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_AssignToInstance) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::AssignToInstance(THIS, uint16 instance_id)"); // @categories Adventures and Expeditions
	{
		Client *THIS;
		uint16 instance_id = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->AssignToInstance(instance_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_RemoveFromInstance); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_RemoveFromInstance) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::RemoveFromInstance(THIS, uint16 instance_id)"); // @categories Adventures and Expeditions
	{
		Client *THIS;
		uint16 instance_id = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->RemoveFromInstance(instance_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_Freeze);
XS(XS_Client_Freeze) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::Freeze(THIS)");
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->SendAppearancePacket(AT_Anim, ANIM_FREEZE);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_UnFreeze);
XS(XS_Client_UnFreeze) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::UnFreeze(THIS)");
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->SendAppearancePacket(AT_Anim, ANIM_STAND);
	}
	XSRETURN_EMPTY;
}


XS(XS_Client_GetAggroCount); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetAggroCount) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetAggroCount(THIS)"); // @categories Script Utility, Hate and Aggro
	{
		Client *THIS;
		int RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetAggroCount();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}


XS(XS_Client_GetCarriedMoney); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetCarriedMoney) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetCarriedMoney(THIS)"); // @categories Currency and Points
	{
		Client *THIS;
		int RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetCarriedMoney();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}


XS(XS_Client_GetAllMoney); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetAllMoney) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetAllMoney(THIS)"); // @categories Currency and Points
	{
		Client *THIS;
		int RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetAllMoney();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}


XS(XS_Client_GetItemInInventory); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetItemInInventory) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetItemInInventory(THIS, int16 slot_id)"); // @categories Inventory and Items
	{
		Client *THIS;
		int16               slot_id = (int16) SvIV(ST(1));
		EQ::ItemInstance *RETVAL = nullptr;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetInv().GetItem(slot_id);
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "QuestItem", (void *) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_SetCustomItemData); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetCustomItemData) {
	dXSARGS;
	if (items != 4)
		Perl_croak(aTHX_ "Usage: Client::SetCustomItemData(THIS, int16 slot_id, string identifier, string value)"); // @categories Inventory and Items
	{
		Client *THIS;
		int16 slot_id = (int16) SvIV(ST(1));
		Const_char *identifier = SvPV_nolen(ST(2));
		Const_char *value      = SvPV_nolen(ST(3));
		VALIDATE_THIS_IS_CLIENT;
		THIS->GetInv().SetCustomItemData(THIS->CharacterID(), slot_id, std::string(identifier), std::string(value));
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetCustomItemData); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetCustomItemData) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::GetCustomItemData(THIS, int16 slot_id, string identifier)"); // @categories Inventory and Items, Corpse
	{
		Client *THIS;
		int16 slot_id = (int16) SvIV(ST(1));
		Const_char *identifier = SvPV_nolen(ST(2));
		Const_char *RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		std::string ret_val = THIS->GetInv().GetCustomItemData(slot_id, std::string(identifier));
		RETVAL = ret_val.c_str();
		sv_setpv(TARG, RETVAL);
		XSprePUSH;
		PUSHTARG;
	}
	XSRETURN(1);
}

XS(XS_Client_OpenLFGuildWindow); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_OpenLFGuildWindow) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::OpenLFGuildWindow(THIS)"); // @categories Script Utility, Guild
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->OpenLFGuildWindow();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_NotifyNewTitlesAvailable); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_NotifyNewTitlesAvailable) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::NotifyNewTitlesAvailable(THIS)"); // @categories Account and Character
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->NotifyNewTitlesAvailable();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_AddAlternateCurrencyValue); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_AddAlternateCurrencyValue) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::AddAlternateCurrencyValue(THIS, uint32 currency_id, int32 amount)"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 currency_id = (uint32) SvUV(ST(1));
		int32  amount      = (int32) SvUV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->AddAlternateCurrencyValue(currency_id, amount);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetAlternateCurrencyValue); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetAlternateCurrencyValue) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::SetAlternateCurrencyValue(THIS, uint32 currency_id, int32 amount)"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 currency_id = (uint32) SvUV(ST(1));
		int32  amount      = (int32) SvUV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetAlternateCurrencyValue(currency_id, amount);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetAlternateCurrencyValue); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetAlternateCurrencyValue) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetAlternateCurrencyValue(THIS, uint32 currency_id)"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 currency_id = (uint32) SvUV(ST(1));
		int32  RETVAL 	   = 0;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetAlternateCurrencyValue(currency_id);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_SendWebLink); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SendWebLink) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Client::SendWebLink(THIS, string website_url)"); // @categories Script Utility
	{
		Client *THIS;
		char   *website = nullptr;
		VALIDATE_THIS_IS_CLIENT;
		if (items > 1) { website = (char *) SvPV_nolen(ST(1)); }

		THIS->SendWebLink(website);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetInstanceID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetInstanceID) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetInstanceID(THIS)"); // @categories Adventures and Expeditions
	{
		Client *THIS;
		int8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetInstanceID();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_HasSpellScribed); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_HasSpellScribed) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::HasSpellScribed(THIS, int spell_id)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		bool RETVAL;
		int  spell_id = (int) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->HasSpellScribed(spell_id);
		ST(0)         = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_SetAccountFlag); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetAccountFlag) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::SetAccountFlag(THIS, string flag, string value)"); // @categories Account and Character
	{
		Client *THIS;
		//char*     flag = (char *)SvPV_nolen(ST(1));
		//char*       value = (char *)SvTRUE(ST(2));

		std::string flag((char *) SvPV_nolen(ST(1)));
		std::string value((char *) SvTRUE(ST(2)));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetAccountFlag(flag, value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetAccountFlag); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetAccountFlag) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetAccountFlag(THIS, string flag)"); // @categories Account and Character
	{
		Client *THIS;
		//char*     flag = (char *)SvPV_nolen(ST(1));
		//char*       value = (char *)SvTRUE(ST(2));

		std::string flag((char *) SvPV_nolen(ST(1)));
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		std::string value = THIS->GetAccountFlag(flag);

		sv_setpv(TARG, value.c_str());
		XSprePUSH;
		PUSHTARG;
	}
	XSRETURN(1);
}

XS(XS_Client_GetHunger); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetHunger) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetHunger(THIS)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetHunger();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetThirst); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetThirst) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetThirst(THIS)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetThirst();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_SetHunger); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetHunger) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetHunger(THIS, in_hunger)"); // @categories Script Utility, Stats and Attributes
	{
		Client *THIS;
		int32 in_hunger = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetHunger(in_hunger);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetThirst); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetThirst) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetThirst(THIS, int32 in_thirst)"); // @categories Account and Character, Stats and Attributes
	{
		Client *THIS;
		int32 in_thirst = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetThirst(in_thirst);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SendTargetCommand); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SendTargetCommand) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SendTargetCommand(THIS, int32 entity_id)"); // @categories Script Utility
	{
		Client *THIS;
		int32 in_entid = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SendTargetCommand(in_entid);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetConsumption); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetConsumption) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::SetHunger(THIS, int32 hunger_amount, int32 thirst_amount)"); // @categories Script Utility, Stats and Attributes
	{
		Client *THIS;
		int32 in_hunger = (uint32) SvUV(ST(1));
		int32 in_thirst = (uint32) SvUV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetConsumption(in_hunger, in_thirst);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SilentMessage); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SilentMessage) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SilentMessage(THIS, string message)"); // @categories Script Utility
	{
		Client *THIS;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		if (THIS->GetTarget() != NULL) {
			if (THIS->GetTarget()->IsNPC()) {
				if (DistanceSquaredNoZ(THIS->GetPosition(), THIS->GetTarget()->GetPosition()) <= 200) {
					if (THIS->GetTarget()->CastToNPC()->IsMoving() &&
					    !THIS->GetTarget()->CastToNPC()->IsOnHatelist(THIS->GetTarget()))
						THIS->GetTarget()->CastToNPC()->PauseWandering(RuleI(NPC, SayPauseTimeInSec));
					THIS->ChannelMessageReceived(8, 0, 100, SvPV_nolen(ST(1)));
				}
			}
		}
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_PlayMP3); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_PlayMP3) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Client::PlayMP3(THIS, string file)"); // @categories Script Utility
	{
		Client *THIS;
		char   *fname = nullptr;
		VALIDATE_THIS_IS_CLIENT;
		if (items > 1) { fname = (char *) SvPV_nolen(ST(1)); }

		THIS->PlayMP3(fname);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_ExpeditionMessage); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_ExpeditionMessage) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::ExpeditionMessage(THIS, int expedition_id, string message)"); // @categories Adventures and Expeditions
	{
		Client *THIS;
		int ExpdID = (int) SvUV(ST(1));
		const char *Message = (const char *) SvPV_nolen(ST(2));
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		THIS->ExpeditionSay(Message, ExpdID);
	}
	XSRETURN_EMPTY;
}

//Client::SendMarqueeMessage(uint32 type, uint32 priority, uint32 fade_in, uint32 fade_out, uint32 duration, std::string msg)

XS(XS_Client_SendMarqueeMessage); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SendMarqueeMessage) {
	dXSARGS;
	if (items != 7)
		Perl_croak(aTHX_ "Usage: Client::SendMarqueeMessage(THIS, uint32 type, uint32 priority, uint32 fade_in, uint32 fade_out, uint32 duration, string msg)"); // @categories Script Utility
	{
		Client *THIS;
		uint32      type     = (uint32) SvUV(ST(1));
		uint32      priority = (uint32) SvUV(ST(2));
		uint32      fade_in  = (uint32) SvUV(ST(3));
		uint32      fade_out = (uint32) SvUV(ST(4));
		uint32      duration = (uint32) SvUV(ST(5));
		std::string msg      = (std::string) SvPV_nolen(ST(6));
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		THIS->SendMarqueeMessage(type, priority, fade_in, fade_out, duration, msg);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SendColoredText); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SendColoredText) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::SendColoredText(uint32 color, string message)"); // @categories Script Utility
	{
		Client *THIS;
		uint32      color = (uint32) SvUV(ST(1));
		std::string msg   = (std::string) SvPV_nolen(ST(2));
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		THIS->SendColoredText(color, msg);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SendSpellAnim); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SendSpellAnim) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: SendSpellAnim(uint16 target_id, uint32 spell_animation_id)");
	{
		Client *THIS;
		uint16 targetid = (uint16) SvUV(ST(1));
		uint16 spell_id = (uint16) SvUV(ST(2));
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		THIS->SendSpellAnim(targetid, spell_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetTargetRingX); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetTargetRingX) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetTargetRingX(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetTargetRingX();
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetTargetRingY); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetTargetRingY) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetTargetRingY(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetTargetRingY();
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetTargetRingZ); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetTargetRingZ) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetTargetRingZ(THIS)"); // @categories Script Utility
	{
		Client *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetTargetRingZ();
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_CalcEXP); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_CalcEXP) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: CalcEXP(THIS, uint8 conlevel)");
	{
		Client *THIS;
		uint8  conlevel = 0xFF;
		uint32 RETVAL;
		if (items == 2)
			conlevel = (uint16) SvUV(ST(1));
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->CalcEXP(conlevel);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_QuestReward); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_QuestReward) {
	dXSARGS;
	if (items < 1 || items > 9)
		Perl_croak(aTHX_ "Usage: Client::QuestReward(THIS, int32 mob, int32 copper, int32 silver, int32 gold, int32 platinum, int32 item_id, int32 exp, [bool faction = false])"); // @categories Currency and Points, Experience and Level, Inventory and Items, Faction
	{
		Client *THIS;
		Mob    *mob = nullptr;
		int32 copper   = 0;
		int32 silver   = 0;
		int32 gold     = 0;
		int32 platinum = 0;
		int32 itemid   = 0;
		int32 exp      = 0;
		bool  faction  = false;

		if (sv_derived_from(ST(0), "THIS")) {
			IV tmp = SvIV((SV *) SvRV(ST(0)));
			THIS = INT2PTR(Client *, tmp);
		} else
			Perl_croak(aTHX_ "THIS is not of type client");
		if (THIS == nullptr)
			Perl_croak(aTHX_ "THIS is nullptr, avoiding crash.");

		if (items > 1) {
			if (sv_derived_from(ST(1), "mob")) {
				IV tmp = SvIV((SV *) SvRV(ST(1)));
				mob = INT2PTR(Mob *, tmp);
			} else
				Perl_croak(aTHX_ "mob is not of type Mob");
			if (mob == nullptr)
				Perl_croak(aTHX_ "mob is nullptr, avoiding crash.");
		}
		if (items > 2) { copper = (int32) SvIV(ST(2)); }
		if (items > 3) { silver = (int32) SvIV(ST(3)); }
		if (items > 4) { gold = (int32) SvIV(ST(4)); }
		if (items > 5) { platinum = (int32) SvIV(ST(5)); }
		if (items > 6) { itemid = (int32) SvIV(ST(6)); }
		if (items > 7) { exp = (int32) SvIV(ST(7)); }
		if (items > 8) { faction = (bool) SvIV(ST(8)); }

		THIS->QuestReward(mob, copper, silver, gold, platinum, itemid, exp, faction);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetMoney);
XS(XS_Client_GetMoney) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: GetMoney(THIS, int8 type, int8 subtype)");
	{
		Client *THIS;
		uint32 RETVAL;
		uint8  type    = (uint8) SvUV(ST(1));
		uint8  subtype = (uint8) SvUV(ST(2));
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetMoney(type, subtype);
		XSprePUSH;
		PUSHn((uint32) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetAccountAge);
XS(XS_Client_GetAccountAge) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: GetAccountAge(THIS)");
	{
		Client *THIS;
		int RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetAccountAge();
		XSprePUSH;
		PUSHn((int) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_Popup2); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_Popup2) {
	dXSARGS;
	if (items < 3 || items > 10)
		Perl_croak(aTHX_ "Usage: Client::Popup2(THIS, string title, string text, uint32 popup_id, uint32 negative_id, uint32 buttons, uint32 duration, string button_name_0, string button_name_1, uint32 sound_controls)"); // @categories Script Utility
	{
		Client *THIS;
		char   *Title = (char *) SvPV_nolen(ST(1));
		char   *Text  = (char *) SvPV_nolen(ST(2));
		uint32 PopupID    = 0;
		uint32 NegativeID = 0;
		uint32 Buttons    = 0;
		uint32 Duration   = 0;
		char *ButtonName0 = 0;
		char *ButtonName1 = 0;
		uint32 SoundControls = 0;
		VALIDATE_THIS_IS_CLIENT;
		if (items > 3) { PopupID = (uint32) SvUV(ST(3)); }
		if (items > 4) { NegativeID = (uint32) SvUV(ST(4)); }
		if (items > 5) { Buttons = (uint32) SvUV(ST(5)); }
		if (items > 6) { Duration = (uint32) SvUV(ST(6)); }
		if (items > 7) { ButtonName0 = (char *) SvPV_nolen(ST(7)); }
		if (items > 8) { ButtonName1 = (char *) SvPV_nolen(ST(8)); }
		if (items > 9) { SoundControls = (uint32) SvUV(ST(9)); }


		THIS->SendFullPopup(Title, Text, PopupID, NegativeID, Buttons, Duration, ButtonName0, ButtonName1,
		                    SoundControls);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetPrimaryWeaponOrnamentation); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetPrimaryWeaponOrnamentation)
{
	dXSARGS;
	if (items != 2) {
		Perl_croak(aTHX_ "Usage: Client::SetPrimaryWeaponOrnamentation(THIS, model_id)"); // @categories Account and Character, Inventory and Items
	}
	{
		Client *THIS;
		uint32 model_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetPrimaryWeaponOrnamentation(model_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetSecondaryWeaponOrnamentation); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetSecondaryWeaponOrnamentation)
{
	dXSARGS;
	if (items != 2) {
		Perl_croak(aTHX_ "Usage: Client::SetSecondaryWeaponOrnamentation(THIS, model_id)"); // @categories Account and Character, Inventory and Items
	}
	{
		Client *THIS;
		uint32 model_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetSecondaryWeaponOrnamentation(model_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetClientMaxLevel); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetClientMaxLevel) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetClientMaxLevel(THIS, int in_level)");
	{
		Client* THIS;
		int in_level = (int)SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetClientMaxLevel(in_level);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetClientMaxLevel); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetClientMaxLevel) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetClientMaxLevel(THIS)");
	{
		Client* THIS;
		int RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetClientMaxLevel();
		XSprePUSH;
		PUSHu((UV)RETVAL);
	}
	XSRETURN(1);
}

DynamicZoneLocation GetDynamicZoneLocationFromHash(HV* hash)
{
	// dynamic zone helper method (caller must validate hash)
	SV** zone_ptr = hv_fetchs(hash, "zone", false);
	SV** x_ptr    = hv_fetchs(hash, "x", false);
	SV** y_ptr    = hv_fetchs(hash, "y", false);
	SV** z_ptr    = hv_fetchs(hash, "z", false);
	SV** h_ptr    = hv_fetchs(hash, "h", false);

	uint32_t zone_id = 0;
	if (zone_ptr && SvIOK(*zone_ptr))
	{
		zone_id = static_cast<uint32_t>(SvIV(*zone_ptr));
	}
	else if (zone_ptr && SvPOK(*zone_ptr))
	{
		zone_id = ZoneID(SvPV_nolen(*zone_ptr));
	}

	// SvNIOK checks for number, integer or double
	float x = (x_ptr && SvNIOK(*x_ptr)) ? static_cast<float>(SvNV(*x_ptr)) : 0.0f;
	float y = (y_ptr && SvNIOK(*y_ptr)) ? static_cast<float>(SvNV(*y_ptr)) : 0.0f;
	float z = (z_ptr && SvNIOK(*z_ptr)) ? static_cast<float>(SvNV(*z_ptr)) : 0.0f;
	float h = (h_ptr && SvNIOK(*h_ptr)) ? static_cast<float>(SvNV(*h_ptr)) : 0.0f;

	return { zone_id, x, y, z, h };
}

Expedition* CreateExpeditionFromHash(Client* client, SV* hash_ref)
{
	if (!hash_ref || !SvROK(hash_ref)) // verify valid reference type
	{
		Perl_croak(aTHX_ "Client::CreateExpedition argument is not a reference type");
	}

	HV* hash = (HV*)SvRV(hash_ref); // dereference and verify type is hash
	if (SvTYPE(hash) != SVt_PVHV)
	{
		Perl_croak(aTHX_ "Client::CreateExpedition reference argument is not to a hash type");
	}

	SV** expedition_info_ptr = hv_fetchs(hash, "expedition", false);
	if (!expedition_info_ptr)
	{
		Perl_croak(aTHX_ "Client::CreateExpedition required 'expedition' key missing from hash");
	}

	if (!SvROK(*expedition_info_ptr) || SvTYPE(SvRV(*expedition_info_ptr)) != SVt_PVHV)
	{
		Perl_croak(aTHX_ "Client::CreateExpedition 'expedition' entry must have a hash table value");
	}

	SV** instance_info_ptr = hv_fetchs(hash, "instance", false);
	if (!instance_info_ptr)
	{
		Perl_croak(aTHX_ "Client::CreateExpedition required 'instance' key missing from hash");
	}

	if (!SvROK(*instance_info_ptr) || SvTYPE(SvRV(*instance_info_ptr)) != SVt_PVHV)
	{
		Perl_croak(aTHX_ "Client::CreateExpedition 'instance' entry must have a hash table value");
	}

	// dereference the nested hash tables and validate required keys
	HV* expedition_hash  = (HV*)SvRV(*expedition_info_ptr);
	SV** name_ptr        = hv_fetchs(expedition_hash, "name", false);
	SV** min_players_ptr = hv_fetchs(expedition_hash, "min_players", false);
	SV** max_players_ptr = hv_fetchs(expedition_hash, "max_players", false);
	SV** disable_msg_ptr = hv_fetchs(expedition_hash, "disable_messages", false);
	if (!name_ptr || !min_players_ptr || !max_players_ptr)
	{
		Perl_croak(aTHX_ "Client::CreateExpedition 'expedition' hash table missing required keys (name, min_players, max_players)");
	}

	HV* instance_hash      = (HV*)SvRV(*instance_info_ptr);
	SV** instance_zone_ptr = hv_fetchs(instance_hash, "zone", false);
	SV** version_ptr       = hv_fetchs(instance_hash, "version", false);
	SV** duration_ptr      = hv_fetchs(instance_hash, "duration", false);
	if (!instance_zone_ptr || !version_ptr || !duration_ptr)
	{
		Perl_croak(aTHX_ "Client::CreateExpedition 'instance' hash table missing required keys (zone, version, duration)");
	}

	uint32_t zone_id = 0;
	if (SvIOK(*instance_zone_ptr))
	{
		zone_id = static_cast<uint32_t>(SvIV(*instance_zone_ptr));
	}
	else if (SvPOK(*instance_zone_ptr))
	{
		zone_id = ZoneID(SvPV_nolen(*instance_zone_ptr));
	}
	else
	{
		Perl_croak(aTHX_ "Client::CreateExpedition zone value in 'instance' table must be int or string");
	}

	uint32_t zone_version  = SvIOK(*version_ptr) ? static_cast<uint32_t>(SvIV(*version_ptr)) : 0;
	uint32_t zone_duration = SvIOK(*duration_ptr) ? static_cast<uint32_t>(SvIV(*duration_ptr)) : 0;

	DynamicZone dz{ zone_id, zone_version, zone_duration, DynamicZoneType::Expedition };
	dz.SetName(SvPOK(*name_ptr) ? SvPV_nolen(*name_ptr) : "");
	dz.SetMinPlayers(SvIOK(*min_players_ptr) ? static_cast<uint32_t>(SvIV(*min_players_ptr)) : 0);
	dz.SetMaxPlayers(SvIOK(*max_players_ptr) ? static_cast<uint32_t>(SvIV(*max_players_ptr)) : 0);

	SV** compass_ptr = hv_fetchs(hash, "compass", false);
	if (compass_ptr && SvROK(*compass_ptr) && SvTYPE(SvRV(*compass_ptr)) == SVt_PVHV)
	{
		auto compass_loc = GetDynamicZoneLocationFromHash((HV*)SvRV(*compass_ptr));
		dz.SetCompass(compass_loc);
	}

	SV** safereturn_ptr = hv_fetchs(hash, "safereturn", false);
	if (safereturn_ptr && SvROK(*safereturn_ptr) && SvTYPE(SvRV(*safereturn_ptr)) == SVt_PVHV)
	{
		auto safereturn_loc = GetDynamicZoneLocationFromHash((HV*)SvRV(*safereturn_ptr));
		dz.SetSafeReturn(safereturn_loc);
	}

	SV** zonein_ptr = hv_fetchs(hash, "zonein", false);
	if (zonein_ptr && SvROK(*zonein_ptr) && SvTYPE(SvRV(*zonein_ptr)) == SVt_PVHV)
	{
		auto zonein_loc = GetDynamicZoneLocationFromHash((HV*)SvRV(*zonein_ptr));
		dz.SetZoneInLocation(zonein_loc);
	}

	bool disable_messages = (disable_msg_ptr && SvIOK(*disable_msg_ptr)) ? SvTRUE(*disable_msg_ptr) : false;

	return client->CreateExpedition(dz, disable_messages);
}

XS(XS_Client_CreateExpedition);
XS(XS_Client_CreateExpedition) {
	dXSARGS;
	if (items != 2 && items != 7 && items != 8) {
		Perl_croak(aTHX_ "Usage: Client::CreateExpedition(THIS, HASHREF expedition_info | string zone_name, uint32 zone_version, uint32 duration, string expedition_name, uint32 min_players, uint32 max_players, [bool disable_messages = false])");
	}

	Client* THIS = nullptr;
	VALIDATE_THIS_IS_CLIENT;

	Expedition* RETVAL = nullptr;
	if (items == 2)
	{
		RETVAL = CreateExpeditionFromHash(THIS, ST(1));
	}
	else
	{
		std::string zone_name(SvPV_nolen(ST(1)));
		uint32 zone_version = (uint32)SvUV(ST(2));
		uint32 duration = (uint32)SvUV(ST(3));
		std::string expedition_name(SvPV_nolen(ST(4)));
		uint32 min_players = (uint32)SvUV(ST(5));
		uint32 max_players = (uint32)SvUV(ST(6));
		bool disable_messages = (items > 7) ? (bool)SvTRUE(ST(7)) : false;

		RETVAL = THIS->CreateExpedition(zone_name, zone_version, duration,
			expedition_name, min_players, max_players, disable_messages);
	}

	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "Expedition", (void*)RETVAL);

	XSRETURN(1);
}

XS(XS_Client_CreateTaskDynamicZone);
XS(XS_Client_CreateTaskDynamicZone) {
	dXSARGS;
	if (items != 3) {
		Perl_croak(aTHX_ "Usage: Client::CreateTaskDynamicZone(THIS, int task_id, HASHREF dz_info)");
	}

	Client* THIS = nullptr;
	VALIDATE_THIS_IS_CLIENT;

	SV* hash_ref = ST(2);
	if (!hash_ref || !SvROK(hash_ref))
	{
		Perl_croak(aTHX_ "Client::CreateTaskDynamicZone argument is not a reference type");
	}

	HV* hash = (HV*)SvRV(hash_ref); // dereference into hash
	if (SvTYPE(hash) != SVt_PVHV)
	{
		Perl_croak(aTHX_ "Client::CreateTaskDynamicZone reference argument is not to a hash type");
	}

	SV** instance_info_ptr = hv_fetchs(hash, "instance", false);
	if (!instance_info_ptr)
	{
		Perl_croak(aTHX_ "Client::CreateTaskDynamicZone required 'instance' key missing from hash");
	}

	if (!SvROK(*instance_info_ptr) || SvTYPE(SvRV(*instance_info_ptr)) != SVt_PVHV)
	{
		Perl_croak(aTHX_ "Client::CreateTaskDynamicZone 'instance' entry must have a hash table value");
	}

	HV* instance_hash      = (HV*)SvRV(*instance_info_ptr);
	SV** instance_zone_ptr = hv_fetchs(instance_hash, "zone", false);
	SV** version_ptr       = hv_fetchs(instance_hash, "version", false);
	SV** duration_ptr      = hv_fetchs(instance_hash, "duration", false);
	if (!instance_zone_ptr || !version_ptr)
	{
		Perl_croak(aTHX_ "Client::CreateTaskDynamicZone 'instance' hash table missing required keys (zone, version, duration)");
	}

	uint32_t zone_id = 0;
	SV* instance_zone = *instance_zone_ptr;
	if (SvIOK(instance_zone))
	{
		zone_id = static_cast<uint32_t>(SvIV(instance_zone));
	}
	else if (SvPOK(instance_zone))
	{
		zone_id = ZoneID(SvPV_nolen(instance_zone));
	}
	else
	{
		Perl_croak(aTHX_ "Client::CreateTaskDynamicZone zone value in 'instance' table must be int or string");
	}

	uint32_t zone_version  = SvIOK(*version_ptr) ? static_cast<uint32_t>(SvIV(*version_ptr)) : 0;

	// tasks override dz duration so duration is ignored here
	DynamicZone dz{ zone_id, zone_version, 0, DynamicZoneType::None };

	SV** compass_ptr = hv_fetchs(hash, "compass", false);
	if (compass_ptr && SvROK(*compass_ptr) && SvTYPE(SvRV(*compass_ptr)) == SVt_PVHV)
	{
		auto compass_loc = GetDynamicZoneLocationFromHash((HV*)SvRV(*compass_ptr));
		dz.SetCompass(compass_loc);
	}

	SV** safereturn_ptr = hv_fetchs(hash, "safereturn", false);
	if (safereturn_ptr && SvROK(*safereturn_ptr) && SvTYPE(SvRV(*safereturn_ptr)) == SVt_PVHV)
	{
		auto safereturn_loc = GetDynamicZoneLocationFromHash((HV*)SvRV(*safereturn_ptr));
		dz.SetSafeReturn(safereturn_loc);
	}

	SV** zonein_ptr = hv_fetchs(hash, "zonein", false);
	if (zonein_ptr && SvROK(*zonein_ptr) && SvTYPE(SvRV(*zonein_ptr)) == SVt_PVHV)
	{
		auto zonein_loc = GetDynamicZoneLocationFromHash((HV*)SvRV(*zonein_ptr));
		dz.SetZoneInLocation(zonein_loc);
	}

	uint32_t task_id = static_cast<uint32_t>(SvUV(ST(1)));

	THIS->CreateTaskDynamicZone(task_id, dz);
}

XS(XS_Client_GetExpedition);
XS(XS_Client_GetExpedition) {
	dXSARGS;
	if (items != 1) {
		Perl_croak(aTHX_ "Usage: Client::GetExpedition(THIS)");
	}
	Client* THIS = nullptr;
	VALIDATE_THIS_IS_CLIENT;

	Expedition* RETVAL = THIS->GetExpedition();

	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "Expedition", (void*)RETVAL);

	XSRETURN(1);
}

XS(XS_Client_GetExpeditionLockouts);
XS(XS_Client_GetExpeditionLockouts) {
	dXSARGS;
	if (items != 1 && items != 2) {
		Perl_croak(aTHX_ "Usage: Client::GetExpeditionLockouts(THIS, [string expedition_name])");
	}

	Client* THIS = nullptr;
	VALIDATE_THIS_IS_CLIENT;

	HV* hash = newHV();
	SV* hash_ref = nullptr; // for expedition event hash if filtering on expedition

	std::string expedition_name;
	if (items == 2)
	{
		expedition_name = SvPV_nolen(ST(1));
	}

	auto lockouts = THIS->GetExpeditionLockouts();

	for (const auto& lockout : lockouts)
	{
		uint32_t name_len = static_cast<uint32_t>(lockout.GetExpeditionName().size());
		uint32_t event_len = static_cast<uint32_t>(lockout.GetEventName().size());

		SV** entry = hv_fetch(hash, lockout.GetExpeditionName().c_str(), name_len, false);
		if (!entry)
		{
			SV* event_hash_ref = newRV_noinc((SV*)newHV()); // takes ownership of hash
			if (!expedition_name.empty() && lockout.GetExpeditionName() == expedition_name)
			{
				hash_ref = event_hash_ref; // save ref to event hash for return
			}
			entry = hv_store(hash, lockout.GetExpeditionName().c_str(), name_len, event_hash_ref, 0);
		}

		if (entry && SvROK(*entry) && SvTYPE(SvRV(*entry)) == SVt_PVHV)
		{
			HV* event_hash = (HV*)SvRV(*entry);
			hv_store(event_hash, lockout.GetEventName().c_str(), event_len,
				newSVuv(lockout.GetSecondsRemaining()), 0);
		}
	}

	SV* rv = &PL_sv_undef;

	if (!expedition_name.empty())
	{
		rv = hash_ref ? sv_2mortal(hash_ref) : &PL_sv_undef; // ref that owns event hash for expedition
	}
	else
	{
		rv = sv_2mortal(newRV_noinc((SV*)hash)); // owns expedition hash
	}

	ST(0) = rv;
	XSRETURN(1);
}

XS(XS_Client_GetLockoutExpeditionUUID);
XS(XS_Client_GetLockoutExpeditionUUID) {
	dXSARGS;
	if (items != 3) {
		Perl_croak(aTHX_ "Usage: Client::GetLockoutExpeditionUUID(THIS, string expedition_name, string event_name)");
	}

	Client* THIS = nullptr;
	VALIDATE_THIS_IS_CLIENT;

	std::string expedition_name = SvPV_nolen(ST(1));
	std::string event_name = SvPV_nolen(ST(2));

	auto lockout = THIS->GetExpeditionLockout(expedition_name, event_name);
	if (lockout)
	{
		XSRETURN_PV(lockout->GetExpeditionUUID().c_str());
	}

	XSRETURN_UNDEF;
}

XS(XS_Client_AddExpeditionLockout);
XS(XS_Client_AddExpeditionLockout) {
	dXSARGS;
	if (items != 4 && items != 5) {
		Perl_croak(aTHX_ "Usage: Client::AddExpeditionLockout(THIS, string expedition_name, string event_name, uint32 seconds, [string uuid])");
	}

	Client* THIS = nullptr;
	VALIDATE_THIS_IS_CLIENT;

	std::string expedition_name(SvPV_nolen(ST(1)));
	std::string event_name(SvPV_nolen(ST(2)));
	uint32 seconds = (uint32)SvUV(ST(3));
	std::string uuid;

	if (items == 5)
	{
		uuid = SvPV_nolen(ST(4));
	}

	THIS->AddNewExpeditionLockout(expedition_name, event_name, seconds, uuid);

	XSRETURN_EMPTY;
}

XS(XS_Client_AddExpeditionLockoutDuration);
XS(XS_Client_AddExpeditionLockoutDuration) {
	dXSARGS;
	if (items != 4 && items != 5) {
		Perl_croak(aTHX_ "Usage: Client::AddExpeditionLockoutDuration(THIS, string expedition_name, string event_name, int seconds, [string uuid])");
	}

	Client* THIS = nullptr;
	VALIDATE_THIS_IS_CLIENT;

	std::string expedition_name(SvPV_nolen(ST(1)));
	std::string event_name(SvPV_nolen(ST(2)));
	int seconds = static_cast<int>(SvUV(ST(3)));
	std::string uuid;

	if (items == 5)
	{
		uuid = SvPV_nolen(ST(4));
	}

	THIS->AddExpeditionLockoutDuration(expedition_name, event_name, seconds, uuid, true);

	XSRETURN_EMPTY;
}

XS(XS_Client_RemoveAllExpeditionLockouts);
XS(XS_Client_RemoveAllExpeditionLockouts) {
	dXSARGS;
	if (items != 1 && items != 2) {
		Perl_croak(aTHX_ "Usage: Client::RemoveAllExpeditionLockouts(THIS, [string expedition_name])");
	}

	Client* THIS = nullptr;
	VALIDATE_THIS_IS_CLIENT;

	std::string expedition_name;
	if (items == 2)
	{
		expedition_name = SvPV_nolen(ST(1));
	}

	THIS->RemoveAllExpeditionLockouts(expedition_name, true);

	XSRETURN_EMPTY;
}

XS(XS_Client_RemoveExpeditionLockout);
XS(XS_Client_RemoveExpeditionLockout) {
	dXSARGS;
	if (items != 3) {
		Perl_croak(aTHX_ "Usage: Client::RemoveExpeditionLockout(THIS, string expedition_name, string event_name)");
	}

	Client* THIS = nullptr;
	VALIDATE_THIS_IS_CLIENT;

	std::string expedition_name(SvPV_nolen(ST(1)));
	std::string event_name(SvPV_nolen(ST(2)));

	THIS->RemoveExpeditionLockout(expedition_name, event_name, true);

	XSRETURN_EMPTY;
}

XS(XS_Client_HasExpeditionLockout);
XS(XS_Client_HasExpeditionLockout) {
	dXSARGS;
	if (items != 3) {
		Perl_croak(aTHX_ "Usage: Client::HasExpeditionLockout(THIS, string expedition_name, string event_name)");
	}

	Client* THIS = nullptr;
	VALIDATE_THIS_IS_CLIENT;

	std::string expedition_name(SvPV_nolen(ST(1)));
	std::string event_name(SvPV_nolen(ST(2)));

	bool result = THIS->HasExpeditionLockout(expedition_name, event_name);
	ST(0) = boolSV(result);

	XSRETURN(1);
}

XS(XS_Client_MovePCDynamicZone);
XS(XS_Client_MovePCDynamicZone) {
	dXSARGS;
	if (items != 2 && items != 3 && items != 4) {
		Perl_croak(aTHX_ "Usage: Client::MovePCDynamicZone(THIS, uint32 zone_id | string zone_name, [int zone_version = -1], [bool message_if_invalid = true])");
	}

	Client* THIS = nullptr;
	VALIDATE_THIS_IS_CLIENT;

	if (SvTYPE(ST(1)) == SVt_PV)
	{
		std::string zone_name(SvPV_nolen(ST(1)));
		int zone_version = (items >= 3) ? static_cast<int>(SvIV(ST(2))) : -1;
		if (items == 4)
		{
			THIS->MovePCDynamicZone(zone_name, zone_version, (bool)SvTRUE(ST(3)));
		}
		else
		{
			THIS->MovePCDynamicZone(zone_name, zone_version);
		}
	}
	else if (SvTYPE(ST(1)) == SVt_IV)
	{
		uint32 zone_id = (uint32)SvUV(ST(1));
		int zone_version = (items >= 3) ? static_cast<int>(SvIV(ST(2))) : -1;
		if (items == 3)
		{
			THIS->MovePCDynamicZone(zone_id, zone_version, (bool)SvTRUE(ST(2)));
		}
		else
		{
			THIS->MovePCDynamicZone(zone_id, zone_version);
		}
	}
	else
	{
		Perl_croak(aTHX_ "Client::MovePCDynamicZone expected an integer or string");
	}

	XSRETURN_EMPTY;
}

XS(XS_Client_Fling); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_Fling) {
	dXSARGS;
	if (items < 5 || items > 7)
		Perl_croak(aTHX_ "Usage: Client::Fling(THIS, value, target_x, target_y, target_z, ignore_los, clipping)");
	{
		Client*		THIS;
		float value = (float) SvNV(ST(1));
		float target_x = (float) SvNV(ST(2));
		float target_y = (float) SvNV(ST(3));
		float target_z = (float) SvNV(ST(4));
		bool ignore_los = false;
		bool clipping = false;
		VALIDATE_THIS_IS_CLIENT;
		if (items > 5)
			ignore_los = (bool) SvTRUE(ST(5));

		if (items > 6)
			clipping = (bool) SvTRUE(ST(6));

		THIS->Fling(value, target_x, target_y, target_z, ignore_los, clipping);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_HasDisciplineLearned); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_HasDisciplineLearned) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::HasDisciplineLearned(THIS, uint16 spell_id)");
	{
		Client *THIS;
		bool has_learned;
		uint16 spell_id = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		has_learned = THIS->HasDisciplineLearned(spell_id);
		ST(0) = boolSV(has_learned);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_GetClassBitmask);
XS(XS_Client_GetClassBitmask) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetClassBitmask(THIS)");
	{
		Client* THIS;
		int client_bitmask = 0;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		client_bitmask = GetPlayerClassBit(THIS->GetClass());
		XSprePUSH;
		PUSHu((UV) client_bitmask);
	}
	XSRETURN(1);
}

XS(XS_Client_GetRaceBitmask);
XS(XS_Client_GetRaceBitmask) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetRaceBitmask(THIS)"); // @categories Stats and Attributes
	{
		Client* THIS;
		int client_bitmask = 0;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		client_bitmask = GetPlayerRaceBit(THIS->GetBaseRace());
		XSprePUSH;
		PUSHu((UV) client_bitmask);
	}
	XSRETURN(1);
}

XS(XS_Client_GetLearnableDisciplines);
XS(XS_Client_GetLearnableDisciplines) {
	dXSARGS;
	if (items < 1 || items > 3)
		Perl_croak(aTHX_ "Usage: Client::GetLearnableDisciplines(THIS, [uint8 min_level, uint8 max_level])");

	uint8 min_level = 1;
	uint8 max_level = 0;
	if (items > 1)
		min_level = (uint8)SvUV(ST(1));
	if (items > 2)
		max_level = (uint8)SvUV(ST(2));

	Client* THIS;
	VALIDATE_THIS_IS_CLIENT;
	auto learnable_disciplines = THIS->GetLearnableDisciplines(min_level, max_level);
	auto learnable_size = learnable_disciplines.size();
	if (learnable_size > 0) {
		EXTEND(sp, learnable_size);
		for (int index = 0; index < learnable_size; ++index) {
			ST(index) = sv_2mortal(newSVuv(learnable_disciplines[index]));
		}
		XSRETURN(learnable_size);
	}
	SV* return_value = &PL_sv_undef;
	ST(0) = return_value;
	XSRETURN(1);
}

XS(XS_Client_GetLearnedDisciplines);
XS(XS_Client_GetLearnedDisciplines) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetLearnedDisciplines(THIS)");

	Client* THIS;
	VALIDATE_THIS_IS_CLIENT;
	auto learned_disciplines = THIS->GetLearnedDisciplines();
	auto learned_size = learned_disciplines.size();
	if (learned_size > 0) {
		EXTEND(sp, learned_size);
		for (int index = 0; index < learned_size; ++index) {
			ST(index) = sv_2mortal(newSVuv(learned_disciplines[index]));
		}
		XSRETURN(learned_size);
	}
	SV* return_value = &PL_sv_undef;
	ST(0) = return_value;
	XSRETURN(1);
}

XS(XS_Client_GetMemmedSpells);
XS(XS_Client_GetMemmedSpells) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetMemmedSpells(THIS)");

	Client* THIS;
	VALIDATE_THIS_IS_CLIENT;
	auto memmed_spells = THIS->GetMemmedSpells();
	auto memmed_size = memmed_spells.size();
	if (memmed_size > 0) {
		EXTEND(sp, memmed_size);
		for (int index = 0; index < memmed_size; ++index) {
			ST(index) = sv_2mortal(newSVuv(memmed_spells[index]));
		}
		XSRETURN(memmed_size);
	}
	SV* return_value = &PL_sv_undef;
	ST(0) = return_value;
	XSRETURN(1);
}

XS(XS_Client_GetScribeableSpells);
XS(XS_Client_GetScribeableSpells) {
	dXSARGS;
	if (items < 1 || items > 3)
		Perl_croak(aTHX_ "Usage: Client::GetScribeableSpells(THIS, [uint8 min_level, uint8 max_level])");

	uint8 min_level = 1;
	uint8 max_level = 0;
	if (items > 1)
		min_level = (uint8)SvUV(ST(1));
	if (items > 2)
		max_level = (uint8)SvUV(ST(2));

	Client* THIS;
	VALIDATE_THIS_IS_CLIENT;
	auto scribeable_spells = THIS->GetScribeableSpells(min_level, max_level);
	auto scribeable_size = scribeable_spells.size();
	if (scribeable_size > 0) {
		EXTEND(sp, scribeable_size);
		for (int index = 0; index < scribeable_size; ++index) {
			ST(index) = sv_2mortal(newSVuv(scribeable_spells[index]));
		}
		XSRETURN(scribeable_size);
	}
	SV* return_value = &PL_sv_undef;
	ST(0) = return_value;
	XSRETURN(1);
}

XS(XS_Client_GetScribedSpells);
XS(XS_Client_GetScribedSpells) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetScribedSpells(THIS)");

	Client* THIS;
	VALIDATE_THIS_IS_CLIENT;
	auto scribed_spells = THIS->GetScribedSpells();
	auto scribed_size = scribed_spells.size();
	if (scribed_size > 0) {
		EXTEND(sp, scribed_size);
		for (int index = 0; index < scribed_size; ++index) {
			ST(index) = sv_2mortal(newSVuv(scribed_spells[index]));
		}
		XSRETURN(scribed_size);
	}
	SV* return_value = &PL_sv_undef;
	ST(0) = return_value;
	XSRETURN(1);
}

XS(XS_Client_GetInventory);
XS(XS_Client_GetInventory) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetInventory(THIS)");
	{
		Client* THIS;
		EQ::InventoryProfile* RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = &THIS->GetInv();
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Inventory", (void *) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_GetAAEXPModifier);
XS(XS_Client_GetAAEXPModifier) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetAAEXPModifier(THIS, uint32 zone_id)");
	{
		Client* THIS;
		double aa_modifier = 1.0f;
		uint32 zone_id = (uint32)SvUV(ST(1));
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		aa_modifier = THIS->GetAAEXPModifier(zone_id);
		XSprePUSH;
		PUSHn((double) aa_modifier);
	}
	XSRETURN(1);
}

XS(XS_Client_GetEXPModifier);
XS(XS_Client_GetEXPModifier) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetEXPModifier(THIS, uint32 zone_id)");
	{
		Client* THIS;
		double exp_modifier = 1.0f;
		uint32 zone_id = (uint32)SvUV(ST(1));
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		exp_modifier = THIS->GetEXPModifier(zone_id);
		XSprePUSH;
		PUSHn((double) exp_modifier);
	}
	XSRETURN(1);
}

XS(XS_Client_SetAAEXPModifier);
XS(XS_Client_SetAAEXPModifier) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::SetAAEXPModifier(THIS, uint32 zone_id, float aa_modifier)");
	{
		Client* THIS;
		uint32 zone_id = (uint32)SvUV(ST(1));
		double aa_modifier = (double) SvNV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetAAEXPModifier(zone_id, aa_modifier);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetEXPModifier);
XS(XS_Client_SetEXPModifier) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::SetEXPModifier(THIS, uint32 zone_id, float exp_modifier)");
	{
		Client* THIS;
		uint32 zone_id = (uint32)SvUV(ST(1));
		double exp_modifier = (double) SvNV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetEXPModifier(zone_id, exp_modifier);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_AddLDoNLoss);
XS(XS_Client_AddLDoNLoss) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::AddLDoNLoss(THIS, uint32 theme_id)");
	{
		Client* THIS;
		uint32 theme_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->UpdateLDoNWinLoss(theme_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_AddLDoNWin);
XS(XS_Client_AddLDoNWin) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::AddLDoNWin(THIS, uint32 theme_id)");
	{
		Client* THIS;
		uint32 theme_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->UpdateLDoNWinLoss(theme_id, true);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SetHideMe);
XS(XS_Client_SetHideMe) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetHideMe(THIS, bool hide_me_state)");
	{
		Client* THIS;
		bool hide_me_state = (bool) SvTRUE(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetHideMe(hide_me_state);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_ResetAllDisciplineTimers);
XS(XS_Client_ResetAllDisciplineTimers) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::ResetAllDisciplineTimers(THIS)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->ResetAllDisciplineTimers();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SendToInstance);
XS(XS_Client_SendToInstance) {
	dXSARGS;
	if (items != 10)
		Perl_croak(aTHX_ "Usage: Client::SendToInstance(THIS, string instance_type, string zone_short_name, uint32 instance_version, float x, float y, float z, float heading, string instance_identifier, uint32 duration)");
	{
		Client* THIS;
		std::string instance_type = (std::string) SvPV_nolen(ST(1));
		std::string zone_short_name = (std::string) SvPV_nolen(ST(2));
		uint32 instance_version = (uint32) SvUV(ST(3));
		float x = (float) SvNV(ST(4));
		float y = (float) SvNV(ST(5));
		float z = (float) SvNV(ST(6));
		float heading = (float) SvNV(ST(7));
		std::string instance_identifier = (std::string) SvPV_nolen(ST(8));
		uint32 duration = (uint32) SvUV(ST(9));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SendToInstance(instance_type, zone_short_name, instance_version, x, y, z, heading, instance_identifier, duration);
  }
  XSRETURN_EMPTY;
}

XS(XS_Client_CountItem);
XS(XS_Client_CountItem) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::CountItem(THIS, uint32 item_id)");
	{
		Client* THIS;
		int item_count = 0;
		uint32 item_id = (uint32) SvUV(ST(1));
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		item_count = THIS->CountItem(item_id);
		XSprePUSH;
		PUSHu((UV) item_count);
	}
	XSRETURN(1);
}

XS(XS_Client_RemoveItem);
XS(XS_Client_RemoveItem) {
	dXSARGS;
	if (items != 2 && items != 3)
		Perl_croak(aTHX_ "Usage: Client::RemoveItem(THIS, uint32 item_id, [uint32 quantity = 1])"); // @categories Spells and Disciplines
	{
		Client *THIS;
		uint32 item_id = (uint32) SvUV(ST(1));
		uint32 quantity = 1;
		VALIDATE_THIS_IS_CLIENT;
		if (items == 3) {
			quantity = (uint32) SvUV(ST(2));
		}

		THIS->RemoveItem(item_id, quantity);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_DialogueWindow); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_DialogueWindow) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::DialogueWindow(THIS, string window_markdown)"); // @categories Script Utility
		{
			Client *THIS;
			dXSTARG;
			VALIDATE_THIS_IS_CLIENT;

			std::string window_markdown(SvPV_nolen(ST(1)));
			DialogueWindow::Render(THIS, window_markdown);
		}
		XSRETURN_EMPTY;
}

XS(XS_Client_DiaWind); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_DiaWind) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::DiaWind(THIS, string window_markdown)"); // @categories Script Utility
		{
			Client *THIS;
			dXSTARG;
			VALIDATE_THIS_IS_CLIENT;

			std::string window_markdown(SvPV_nolen(ST(1)));
			DialogueWindow::Render(THIS, window_markdown);

		}
		XSRETURN_EMPTY;
}

XS(XS_Client_GetIPExemption);
XS(XS_Client_GetIPExemption) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetIPExemption(THIS)"); // @categories Account and Character
	{
		Client* THIS;
		int exemption_amount = 0;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		exemption_amount = THIS->GetIPExemption();
		XSprePUSH;
		PUSHi((IV) exemption_amount);
	}
	XSRETURN(1);	
}

XS(XS_Client_GetIPString);
XS(XS_Client_GetIPString) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetIPString(THIS)"); // @categories Account and Character
	{
		Client *THIS;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		std::string ip_string = THIS->GetIPString();
		sv_setpv(TARG, ip_string.c_str());
		XSprePUSH;
		PUSHTARG;
	}
	XSRETURN(1);
}

XS(XS_Client_SetIPExemption); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetIPExemption) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetIPExemption(THIS, int exemption_amount)"); // @categories Account and Character
	{
		Client *THIS;
		int exemption_amount = (int) SvIV(ST(1));
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetIPExemption(exemption_amount);
  }
	XSRETURN_EMPTY;
}

XS(XS_Client_ReadBookByName);
XS(XS_Client_ReadBookByName) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::ReadBookByName(THIS, string book_name, uint8 book_type)"); // @categories Script Utility
	{
		Client *THIS;
		std::string book_name(SvPV_nolen(ST(1)));
		uint8 book_type = (uint8) SvUV(ST(2));
		VALIDATE_THIS_IS_CLIENT;
		THIS->ReadBookByName(book_name, book_type);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_UntrainDiscBySpellID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_UntrainDiscBySpellID) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Client::UntrainDiscBySpellID(THIS, uint16 spell_id, [bool update_client = true])"); // @categories Spells and Disciplines
	{
		Client *THIS;
		uint16 spell_id = (uint16) SvUV(ST(1));
		bool update_client = true;
		VALIDATE_THIS_IS_CLIENT;
		if (items == 3) {
			update_client = (bool) SvTRUE(ST(2));
		}

		THIS->UntrainDiscBySpellID(spell_id, update_client);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_SummonBaggedItems); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SummonBaggedItems) {
	dXSARGS;
	if (items != 3) {
		Perl_croak(aTHX_ "Usage: Client::SummonBaggedItems(THIS, uint32 bag_item_id, ARRAYREF bag_items_array)"); // @categories Inventory and Items, Script Utility
	}

	Client* THIS;
	VALIDATE_THIS_IS_CLIENT;

	uint32 bag_item_id = (uint32) SvUV(ST(1));

	// verify we're receiving a reference to an array type
	SV* bag_items_avref = ST(2);
	if (!bag_items_avref || !SvROK(bag_items_avref) || SvTYPE(SvRV(bag_items_avref)) != SVt_PVAV) {
		Perl_croak(aTHX_ "Client::SummonBaggedItems second argument is not a reference to an array");
	}

	// dereference into the array
	AV* bag_items_av = (AV*)SvRV(bag_items_avref);

	std::vector<ServerLootItem_Struct> bagged_items;

	auto count = av_len(bag_items_av) + 1;
	for (int i = 0; i < count; ++i) {
		SV** element = av_fetch(bag_items_av, i, 0);

		// verify array element is a hash reference containing item details
		if (element && SvROK(*element) && SvTYPE(SvRV(*element)) == SVt_PVHV) {
			HV* hash = (HV*)SvRV(*element); // dereference

			SV** item_id_ptr = hv_fetchs(hash, "item_id", false);
			SV** item_charges_ptr = hv_fetchs(hash, "charges", false);
			SV** attuned_ptr = hv_fetchs(hash, "attuned", false);
			SV** augment_one_ptr = hv_fetchs(hash, "augment_one", false);
			SV** augment_two_ptr = hv_fetchs(hash, "augment_two", false);
			SV** augment_three_ptr = hv_fetchs(hash, "augment_three", false);
			SV** augment_four_ptr = hv_fetchs(hash, "augment_four", false);
			SV** augment_five_ptr = hv_fetchs(hash, "augment_five", false);
			SV** augment_six_ptr = hv_fetchs(hash, "augment_six", false);			
			if (item_id_ptr && item_charges_ptr) {
				ServerLootItem_Struct item{};
				item.item_id = static_cast<uint32>(SvUV(*item_id_ptr));
				item.charges = static_cast<int16>(SvIV(*item_charges_ptr));
				item.attuned = attuned_ptr ? static_cast<uint8>(SvUV(*attuned_ptr)) : 0;
				item.aug_1 = augment_one_ptr ? static_cast<uint32>(SvUV(*augment_one_ptr)) : 0;
				item.aug_2 = augment_two_ptr ? static_cast<uint32>(SvUV(*augment_two_ptr)) : 0;
				item.aug_3 = augment_three_ptr ? static_cast<uint32>(SvUV(*augment_three_ptr)) : 0;
				item.aug_4 = augment_four_ptr ? static_cast<uint32>(SvUV(*augment_four_ptr)) : 0;
				item.aug_5 = augment_five_ptr ? static_cast<uint32>(SvUV(*augment_five_ptr)) : 0;
				item.aug_6 = augment_six_ptr ? static_cast<uint32>(SvUV(*augment_six_ptr)) : 0;
				bagged_items.emplace_back(item);
			}
		}
	}

	THIS->SummonBaggedItems(bag_item_id, bagged_items);

	XSRETURN_EMPTY;
}

XS(XS_Client_RemoveLDoNLoss);
XS(XS_Client_RemoveLDoNLoss) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::RemoveLDoNLoss(THIS, uint32 theme_id)");
	{
		Client* THIS;
		uint32 theme_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->UpdateLDoNWinLoss(theme_id, false, true);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_RemoveLDoNWin);
XS(XS_Client_RemoveLDoNWin) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::RemoveLDoNWin(THIS, uint32 theme_id)");
	{
		Client* THIS;
		uint32 theme_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->UpdateLDoNWinLoss(theme_id, true, true);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetFreeDisciplineSlot); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetFreeDisciplineSlot) {
	dXSARGS;
	if (items != 1 || items != 2)
		Perl_croak(aTHX_ "Usage: Client::GetFreeDisciplineSlot(THIS, [int starting_slot = 0])"); // @categories Spells and Disciplines
	{
		Client *THIS;
		int free_discipline_slot;
		int starting_slot = 0;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		if (items == 2) {
			starting_slot = SvIV(ST(1));
		}

		free_discipline_slot = THIS->GetNextAvailableDisciplineSlot(starting_slot);
		XSprePUSH;
		PUSHi((IV) free_discipline_slot);
	}
	XSRETURN(1);
}

XS(XS_Client_ScribeSpells); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_ScribeSpells) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::ScribeSpells(THIS, uint8 min_level, uint8 max_level)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		uint8 min_level = (uint8) SvUV(ST(1));
		uint8 max_level = (uint8) SvUV(ST(2));
		uint16 scribed_spells = 0;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;

		scribed_spells = THIS->ScribeSpells(min_level, max_level);
		XSprePUSH;
		PUSHu((UV) scribed_spells);
	}
	XSRETURN(1);
}

XS(XS_Client_LearnDisciplines); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_LearnDisciplines) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Client::LearnDisciplines(THIS, uint8 min_level, uint8 max_level)"); // @categories Spells and Disciplines
	{
		Client *THIS;
		uint8 min_level = (uint8) SvUV(ST(1));
		uint8 max_level = (uint8) SvUV(ST(2));
		uint16 learned_disciplines = 0;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;

		learned_disciplines = THIS->LearnDisciplines(min_level, max_level);
		XSprePUSH;
		PUSHu((UV) learned_disciplines);
	}
	XSRETURN(1);
}

XS(XS_Client_ResetCastbarCooldownBySlot);
XS(XS_Client_ResetCastbarCooldownBySlot) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::ResetCastbarCooldownBySlot(THIS, int slot)");
	{
		Client* THIS;
		int slot = (int) SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->ResetCastbarCooldownBySlot(slot);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_ResetAllCastbarCooldowns);
XS(XS_Client_ResetAllCastbarCooldowns) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::ResetAllCastbarCooldowns(THIS)");
	{
		Client* THIS;
		VALIDATE_THIS_IS_CLIENT;
		THIS->ResetAllCastbarCooldowns();
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_ResetCastbarCooldownBySpellID);
XS(XS_Client_ResetCastbarCooldownBySpellID) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::ResetCastbarCooldownBySpellID(THIS, uint32 spell_id)");
	{
		Client* THIS;
		uint32 spell_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->ResetCastbarCooldownBySpellID(spell_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_UnscribeSpellBySpellID);
XS(XS_Client_UnscribeSpellBySpellID) {
	dXSARGS;
	if (items != 2 && items != 3)
		Perl_croak(aTHX_ "Usage: Client::UnscribeSpellBySpellID(THIS, uint16 spell_id, [bool update_client = true])");
	{
		Client* THIS;
		uint16 spell_id = (uint16) SvUV(ST(1));
		bool update_client = true;
		VALIDATE_THIS_IS_CLIENT;

		if (items == 3) {
			update_client = (bool) SvTRUE(ST(2));
		}

		THIS->UnscribeSpellBySpellID(spell_id, update_client);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetEnvironmentDamageModifier); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetEnvironmentDamageModifier) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetEnvironmentDamageModifier(THIS)"); // @categories Script Utility
	{
		Client* THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetEnvironmentDamageModifier();
		XSprePUSH;
		PUSHi((IV)RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_SetEnvironmentDamageModifier); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetEnvironmentDamageModifier) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Client::SetEnvironmentDamageModifier(THIS, int32 modifier)"); //  @categories Script Utility
	{
		Client* THIS;
		int32 modifier = (int32)SvIV(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetEnvironmentDamageModifier(modifier);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetInvulnerableEnvironmentDamage); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetInvulnerableEnvironmentDamage) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::InvulnerableEnvironmentDamage(THIS)"); // @categories Script Utility
	{
		Client* THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetInvulnerableEnvironmentDamage();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Client_SetInvulnerableEnvironmentDamage); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_SetInvulnerableEnvironmentDamage) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage:Client::SetInvulnerableEnvironmentDamage(THIS, bool invulnerable)"); //  @categories Script Utility
	{
		Client *THIS;
		bool invul = (bool)SvTRUE(ST(1));
		VALIDATE_THIS_IS_CLIENT;
		THIS->SetInvulnerableEnvironmentDamage(invul);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_AddItem);
XS(XS_Client_AddItem) {
	dXSARGS;
	if (items != 2) {
		Perl_croak(aTHX_ "Usage: Client::AddItem(THIS, HASHREF item_table)");
	}

	Client *THIS;
	VALIDATE_THIS_IS_CLIENT;

	SV* item_table = ST(1);
	if (!item_table || !SvROK(item_table)) {
		Perl_croak(aTHX_ "Client::AddItem argument is not a reference type");
	}

	HV* item_table_hash = (HV*)SvRV(item_table);
	if (SvTYPE(item_table_hash) != SVt_PVHV) {
		Perl_croak(aTHX_ "Client::AddItem reference argument is not to a hash type");
	}

	SV** item_id_ptr = hv_fetchs(item_table_hash, "item_id", false);
	SV** item_charges_ptr = hv_fetchs(item_table_hash, "charges", false);
	SV** augment_one_ptr = hv_fetchs(item_table_hash, "augment_one", false);
	SV** augment_two_ptr = hv_fetchs(item_table_hash, "augment_two", false);
	SV** augment_three_ptr = hv_fetchs(item_table_hash, "augment_three", false);
	SV** augment_four_ptr = hv_fetchs(item_table_hash, "augment_four", false);
	SV** augment_five_ptr = hv_fetchs(item_table_hash, "augment_five", false);
	SV** augment_six_ptr = hv_fetchs(item_table_hash, "augment_six", false);
	SV** attuned_ptr = hv_fetchs(item_table_hash, "attuned", false);
	SV** slot_id_ptr = hv_fetchs(item_table_hash, "slot_id", false);
	if (item_id_ptr && item_charges_ptr) {
		uint32 item_id = static_cast<uint32>(SvUV(*item_id_ptr));
		int16 charges = static_cast<int16>(SvIV(*item_charges_ptr));
		uint32 augment_one = augment_one_ptr ? static_cast<uint32>(SvUV(*augment_one_ptr)) : 0;
		uint32 augment_two = augment_two_ptr ? static_cast<uint32>(SvUV(*augment_two_ptr)) : 0;
		uint32 augment_three = augment_three_ptr ? static_cast<uint32>(SvUV(*augment_three_ptr)) : 0;
		uint32 augment_four = augment_four_ptr ? static_cast<uint32>(SvUV(*augment_four_ptr)) : 0;
		uint32 augment_five = augment_five_ptr ? static_cast<uint32>(SvUV(*augment_five_ptr)) : 0;
		uint32 augment_six = augment_six_ptr ? static_cast<uint32>(SvUV(*augment_six_ptr)) : 0;
		bool attuned = attuned_ptr ? static_cast<bool>(SvTRUE(*attuned_ptr)) : false;
		uint16 slot_id = slot_id_ptr ? static_cast<uint16>(SvUV(*slot_id_ptr)) : EQ::invslot::slotCursor;
		THIS->SummonItem(
			item_id,
			charges,
			augment_one,
			augment_two,
			augment_three,
			augment_four,
			augment_five,
			augment_six,
			attuned,
			slot_id
		);
	}
	
	XSRETURN_EMPTY;
}

XS(XS_Client_AddPlatinum); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_AddPlatinum) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Client::AddPlatinum(THIS, uint32 platinum, [bool update_client = false])"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 platinum = (uint32) SvUV(ST(1));
		bool update_client = false;
		VALIDATE_THIS_IS_CLIENT;

		if (items == 3) {
			update_client = (bool) SvTRUE(ST(2));
		}

		THIS->AddPlatinum(platinum, update_client);
	}
	XSRETURN_EMPTY;
}

XS(XS_Client_GetCarriedPlatinum); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_GetCarriedPlatinum) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Client::GetCarriedPlatinum(THIS)"); // @categories Currency and Points
	{
		Client *THIS;
		int RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_CLIENT;
		RETVAL = THIS->GetCarriedPlatinum();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Client_TakePlatinum); /* prototype to pass -Wmissing-prototypes */
XS(XS_Client_TakePlatinum) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Client::TakePlatinum(THIS, uint32 platinum, [bool update_client = false])"); // @categories Currency and Points
	{
		Client *THIS;
		uint32 platinum = (uint32) SvUV(ST(1));
		bool has_money = false;
		bool update_client = false;
		VALIDATE_THIS_IS_CLIENT;

		if (items == 3) {
			update_client = (bool) SvTRUE(ST(2));
		}

		has_money = THIS->TakePlatinum(platinum, update_client);
		ST(0) = boolSV(has_money);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Client); /* prototype to pass -Wmissing-prototypes */
XS(boot_Client) {
	dXSARGS;
	char file[256];
	strncpy(file, __FILE__, 256);
	file[255] = 0;

	if (items != 1)
		fprintf(stderr, "boot_quest does not take any arguments.");
	char buf[128];

	//add the strcpy stuff to get rid of const warnings....

	XS_VERSION_BOOTCHECK;
	newXSproto(strcpy(buf, "AccountID"), XS_Client_AccountID, file, "$");
	newXSproto(strcpy(buf, "AccountName"), XS_Client_AccountName, file, "$");
	newXSproto(strcpy(buf, "AddAAPoints"), XS_Client_AddAAPoints, file, "$$");
	newXSproto(strcpy(buf, "AddAlternateCurrencyValue"), XS_Client_AddAlternateCurrencyValue, file, "$$$");
	newXSproto(strcpy(buf, "AddCrystals"), XS_Client_AddCrystals, file, "$$");
	newXSproto(strcpy(buf, "AddEXP"), XS_Client_AddEXP, file, "$$;$$");
	newXSproto(strcpy(buf, "AddExpeditionLockout"), XS_Client_AddExpeditionLockout, file, "$$$$;$");
	newXSproto(strcpy(buf, "AddExpeditionLockoutDuration"), XS_Client_AddExpeditionLockoutDuration, file, "$$$$;$");
	newXSproto(strcpy(buf, "AddItem"), XS_Client_AddItem, file, "$$");
	newXSproto(strcpy(buf, "AddLDoNLoss"), XS_Client_AddLDoNLoss, file, "$$");
	newXSproto(strcpy(buf, "AddLDoNWin"), XS_Client_AddLDoNWin, file, "$$");
	newXSproto(strcpy(buf, "AddLevelBasedExp"), XS_Client_AddLevelBasedExp, file, "$$;$$");
	newXSproto(strcpy(buf, "AddMoneyToPP"), XS_Client_AddMoneyToPP, file, "$$$$$;$");
	newXSproto(strcpy(buf, "AddPlatinum"), XS_Client_AddPlatinum, file, "$$;$");
	newXSproto(strcpy(buf, "AddPVPPoints"), XS_Client_AddPVPPoints, file, "$$");
	newXSproto(strcpy(buf, "AddSkill"), XS_Client_AddSkill, file, "$$$");
	newXSproto(strcpy(buf, "Admin"), XS_Client_Admin, file, "$");
	newXSproto(strcpy(buf, "AssignTask"), XS_Client_AssignTask, file, "$$$;$");
	newXSproto(strcpy(buf, "AssignToInstance"), XS_Client_AssignToInstance, file, "$$");
	newXSproto(strcpy(buf, "AutoSplitEnabled"), XS_Client_AutoSplitEnabled, file, "$");
	newXSproto(strcpy(buf, "BreakInvis"), XS_Client_BreakInvis, file, "$");
	newXSproto(strcpy(buf, "CalcEXP"), XS_Client_CalcEXP, file, "$");
	newXSproto(strcpy(buf, "CalcPriceMod"), XS_Client_CalcPriceMod, file, "$;$$");
	newXSproto(strcpy(buf, "CanHaveSkill"), XS_Client_CanHaveSkill, file, "$$");
	newXSproto(strcpy(buf, "ChangeLastName"), XS_Client_ChangeLastName, file, "$$");
	newXSproto(strcpy(buf, "CharacterID"), XS_Client_CharacterID, file, "$");
	newXSproto(strcpy(buf, "CheckIncreaseSkill"), XS_Client_CheckIncreaseSkill, file, "$$;$");
	newXSproto(strcpy(buf, "CheckSpecializeIncrease"), XS_Client_CheckSpecializeIncrease, file, "$$");
	newXSproto(strcpy(buf, "ClearCompassMark"), XS_Client_ClearCompassMark, file, "$");
	newXSproto(strcpy(buf, "ClearZoneFlag"), XS_Client_ClearZoneFlag, file, "$$");
	newXSproto(strcpy(buf, "Connected"), XS_Client_Connected, file, "$");
	newXSproto(strcpy(buf, "CountItem"), XS_Client_CountItem, file, "$$");
	newXSproto(strcpy(buf, "CreateExpedition"), XS_Client_CreateExpedition, file, "$$$$$$$;$");
	newXSproto(strcpy(buf, "CreateTaskDynamicZone"), XS_Client_CreateTaskDynamicZone, file, "$$");
	newXSproto(strcpy(buf, "DecreaseByID"), XS_Client_DecreaseByID, file, "$$$");
	newXSproto(strcpy(buf, "DeleteItemInInventory"), XS_Client_DeleteItemInInventory, file, "$$;$$");
	newXSproto(strcpy(buf, "DiaWind"), XS_Client_DiaWind, file, "$$");
	newXSproto(strcpy(buf, "DialogueWindow"), XS_Client_DialogueWindow, file, "$$");
	newXSproto(strcpy(buf, "Disconnect"), XS_Client_Disconnect, file, "$");
	newXSproto(strcpy(buf, "DropItem"), XS_Client_DropItem, file, "$$");
	newXSproto(strcpy(buf, "Duck"), XS_Client_Duck, file, "$");
	newXSproto(strcpy(buf, "DyeArmorBySlot"), XS_Client_DyeArmorBySlot, file, "$$$$$;$");
	newXSproto(strcpy(buf, "Escape"), XS_Client_Escape, file, "$");
	newXSproto(strcpy(buf, "ExpeditionMessage"), XS_Client_ExpeditionMessage, file, "$$$");
	newXSproto(strcpy(buf, "FailTask"), XS_Client_FailTask, file, "$$");
	newXSproto(strcpy(buf, "FindEmptyMemSlot"), XS_Client_FindEmptyMemSlot, file, "$");
	newXSproto(strcpy(buf, "FindMemmedSpellBySlot"), XS_Client_FindMemmedSpellBySlot, file, "$$");
	newXSproto(strcpy(buf, "FindMemmedSpellBySpellID"), XS_Client_FindMemmedSpellBySpellID, file, "$$");
	newXSproto(strcpy(buf, "Fling"), XS_Client_Fling, file, "$$$$$;$$");
	newXSproto(strcpy(buf, "ForageItem"), XS_Client_ForageItem, file, "$");
	newXSproto(strcpy(buf, "Freeze"), XS_Client_Freeze, file, "$");
	newXSproto(strcpy(buf, "GMKill"), XS_Client_GMKill, file, "$");
	newXSproto(strcpy(buf, "GetAAEXPModifier"), XS_Client_GetAAEXPModifier, file, "$$");
	newXSproto(strcpy(buf, "GetAAExp"), XS_Client_GetAAExp, file, "$");
	newXSproto(strcpy(buf, "GetAALevel"), XS_Client_GetAALevel, file, "$$");
	newXSproto(strcpy(buf, "GetAAPercent"), XS_Client_GetAAPercent, file, "$");
	newXSproto(strcpy(buf, "GetAAPoints"), XS_Client_GetAAPoints, file, "$$");
	newXSproto(strcpy(buf, "GetAFK"), XS_Client_GetAFK, file, "$");
	newXSproto(strcpy(buf, "GetAccountAge"), XS_Client_GetAccountAge, file, "$");
	newXSproto(strcpy(buf, "GetAccountFlag"), XS_Client_GetAccountFlag, file, "$$");
	newXSproto(strcpy(buf, "GetAggroCount"), XS_Client_GetAggroCount, file, "$");
	newXSproto(strcpy(buf, "GetAllMoney"), XS_Client_GetAllMoney, file, "$");
	newXSproto(strcpy(buf, "GetAlternateCurrencyValue"), XS_Client_GetAlternateCurrencyValue, file, "$$");
	newXSproto(strcpy(buf, "GetAnon"), XS_Client_GetAnon, file, "$");
	newXSproto(strcpy(buf, "GetAugmentAt"), XS_Client_GetAugmentAt, file, "$$$");
	newXSproto(strcpy(buf, "GetAugmentIDAt"), XS_Client_GetAugmentIDAt, file, "$$$");
	newXSproto(strcpy(buf, "GetBaseAGI"), XS_Client_GetBaseAGI, file, "$");
	newXSproto(strcpy(buf, "GetBaseCHA"), XS_Client_GetBaseCHA, file, "$");
	newXSproto(strcpy(buf, "GetBaseDEX"), XS_Client_GetBaseDEX, file, "$");
	newXSproto(strcpy(buf, "GetBaseFace"), XS_Client_GetBaseFace, file, "$");
	newXSproto(strcpy(buf, "GetBaseINT"), XS_Client_GetBaseINT, file, "$");
	newXSproto(strcpy(buf, "GetBaseSTA"), XS_Client_GetBaseSTA, file, "$");
	newXSproto(strcpy(buf, "GetBaseSTR"), XS_Client_GetBaseSTR, file, "$");
	newXSproto(strcpy(buf, "GetBaseWIS"), XS_Client_GetBaseWIS, file, "$");
	newXSproto(strcpy(buf, "GetBecomeNPCLevel"), XS_Client_GetBecomeNPCLevel, file, "$");
	newXSproto(strcpy(buf, "GetBindHeading"), XS_Client_GetBindHeading, file, "$$");
	newXSproto(strcpy(buf, "GetBindX"), XS_Client_GetBindX, file, "$$");
	newXSproto(strcpy(buf, "GetBindY"), XS_Client_GetBindY, file, "$$");
	newXSproto(strcpy(buf, "GetBindZ"), XS_Client_GetBindZ, file, "$$");
	newXSproto(strcpy(buf, "GetBindZoneID"), XS_Client_GetBindZoneID, file, "$$");
	newXSproto(strcpy(buf, "GetCarriedMoney"), XS_Client_GetCarriedMoney, file, "$");
	newXSproto(strcpy(buf, "GetCarriedPlatinum"), XS_Client_GetCarriedPlatinum, file, "$");
	newXSproto(strcpy(buf, "GetCharacterFactionLevel"), XS_Client_GetCharacterFactionLevel, file, "$$");
	newXSproto(strcpy(buf, "GetClassBitmask"), XS_Client_GetClassBitmask, file, "$");
	newXSproto(strcpy(buf, "GetClientMaxLevel"), XS_Client_GetClientMaxLevel, file, "$");
	newXSproto(strcpy(buf, "GetClientVersion"), XS_Client_GetClientVersion, file, "$");
	newXSproto(strcpy(buf, "GetClientVersionBit"), XS_Client_GetClientVersionBit, file, "$");
	newXSproto(strcpy(buf, "GetCorpseCount"), XS_Client_GetCorpseCount, file, "$");
	newXSproto(strcpy(buf, "GetCorpseID"), XS_Client_GetCorpseID, file, "$$");
	newXSproto(strcpy(buf, "GetCorpseItemAt"), XS_Client_GetCorpseItemAt, file, "$$$");
	newXSproto(strcpy(buf, "GetCustomItemData"), XS_Client_GetCustomItemData, file, "$$$");
	newXSproto(strcpy(buf, "GetDiscSlotBySpellID"), XS_Client_GetDiscSlotBySpellID, file, "$$");
	newXSproto(strcpy(buf, "GetDisciplineTimer"), XS_Client_GetDisciplineTimer, file, "$$");
	newXSproto(strcpy(buf, "GetDuelTarget"), XS_Client_GetDuelTarget, file, "$");
	newXSproto(strcpy(buf, "GetEnvironmentDamageModifier"), XS_Client_GetEnvironmentDamageModifier, file, "$");
	newXSproto(strcpy(buf, "GetEXP"), XS_Client_GetEXP, file, "$");
	newXSproto(strcpy(buf, "GetEXPModifier"), XS_Client_GetEXPModifier, file, "$$");
	newXSproto(strcpy(buf, "GetEbonCrystals"), XS_Client_GetEbonCrystals, file, "$");
	newXSproto(strcpy(buf, "GetEndurance"), XS_Client_GetEndurance, file, "$");
	newXSproto(strcpy(buf, "GetEnduranceRatio"), XS_Client_GetEnduranceRatio, file, "$");
	newXSproto(strcpy(buf, "GetExpedition"), XS_Client_GetExpedition, file, "$");
	newXSproto(strcpy(buf, "GetExpeditionLockouts"), XS_Client_GetExpeditionLockouts, file, "$;$");
	newXSproto(strcpy(buf, "GetFace"), XS_Client_GetFace, file, "$");
	newXSproto(strcpy(buf, "GetFactionLevel"), XS_Client_GetFactionLevel, file, "$$$$$$$$");
	newXSproto(strcpy(buf, "GetFeigned"), XS_Client_GetFeigned, file, "$");
	newXSproto(strcpy(buf, "GetFreeDisciplineSlot"), XS_Client_GetFreeDisciplineSlot, file, "$;$");
	newXSproto(strcpy(buf, "GetFreeSpellBookSlot"), XS_Client_GetFreeSpellBookSlot, file, "$;$");
	newXSproto(strcpy(buf, "GetGM"), XS_Client_GetGM, file, "$");
	newXSproto(strcpy(buf, "GetGroup"), XS_Client_GetGroup, file, "$");
	newXSproto(strcpy(buf, "GetGroupPoints"), XS_Client_GetGroupPoints, file, "$");
	newXSproto(strcpy(buf, "GetHorseId"), XS_Client_GetHorseId, file, "$");
	newXSproto(strcpy(buf, "GetHunger"), XS_Client_GetHunger, file, "$$");
	newXSproto(strcpy(buf, "GetIP"), XS_Client_GetIP, file, "$");
	newXSproto(strcpy(buf, "GetIPExemption"), XS_Client_GetIPExemption, file, "$");
	newXSproto(strcpy(buf, "GetIPString"), XS_Client_GetIPString, file, "$");
	newXSproto(strcpy(buf, "GetInstanceID"), XS_Client_GetInstanceID, file, "$$");
	newXSproto(strcpy(buf, "GetInstrumentMod"), XS_Client_GetInstrumentMod, file, "$$");
	newXSproto(strcpy(buf, "GetInventory"), XS_Client_GetInventory, file, "$");
	newXSproto(strcpy(buf, "GetInvulnerableEnvironmentDamage"), XS_Client_GetInvulnerableEnvironmentDamage, file, "$");
	newXSproto(strcpy(buf, "GetItemAt"), XS_Client_GetItemAt, file, "$$");
	newXSproto(strcpy(buf, "GetItemIDAt"), XS_Client_GetItemIDAt, file, "$$");
	newXSproto(strcpy(buf, "GetItemInInventory"), XS_Client_GetItemInInventory, file, "$$");
	newXSproto(strcpy(buf, "GetLDoNLosses"), XS_Client_GetLDoNLosses, file, "$");
	newXSproto(strcpy(buf, "GetLDoNLossesTheme"), XS_Client_GetLDoNLossesTheme, file, "$$");
	newXSproto(strcpy(buf, "GetLDoNPointsTheme"), XS_Client_GetLDoNPointsTheme, file, "$");
	newXSproto(strcpy(buf, "GetLDoNWins"), XS_Client_GetLDoNWins, file, "$");
	newXSproto(strcpy(buf, "GetLDoNWinsTheme"), XS_Client_GetLDoNWinsTheme, file, "$$");
	newXSproto(strcpy(buf, "GetLanguageSkill"), XS_Client_GetLanguageSkill, file, "$$");
	newXSproto(strcpy(buf, "GetLearnableDisciplines"), XS_Client_GetLearnableDisciplines, file, "$;$$");
	newXSproto(strcpy(buf, "GetLearnedDisciplines"), XS_Client_GetLearnedDisciplines, file, "$");
	newXSproto(strcpy(buf, "GetLockoutExpeditionUUID"), XS_Client_GetLockoutExpeditionUUID, file, "$$$");
	newXSproto(strcpy(buf, "GetMaxEndurance"), XS_Client_GetMaxEndurance, file, "$");
	newXSproto(strcpy(buf, "GetMemmedSpells"), XS_Client_GetMemmedSpells, file, "$");
	newXSproto(strcpy(buf, "GetModCharacterFactionLevel"), XS_Client_GetModCharacterFactionLevel, file, "$$");
	newXSproto(strcpy(buf, "GetMoney"), XS_Client_GetMoney, file, "$$$");
	newXSproto(strcpy(buf, "GetPVP"), XS_Client_GetPVP, file, "$");
	newXSproto(strcpy(buf, "GetPVPPoints"), XS_Client_GetPVPPoints, file, "$");
	newXSproto(strcpy(buf, "GetRaceBitmask"), XS_Client_GetRaceBitmask, file, "$");
	newXSproto(strcpy(buf, "GetRadiantCrystals"), XS_Client_GetRadiantCrystals, file, "$");
	newXSproto(strcpy(buf, "GetRaid"), XS_Client_GetRaid, file, "$");
	newXSproto(strcpy(buf, "GetRaidPoints"), XS_Client_GetRaidPoints, file, "$");
	newXSproto(strcpy(buf, "GetRawItemAC"), XS_Client_GetRawItemAC, file, "$");
	newXSproto(strcpy(buf, "GetRawSkill"), XS_Client_GetRawSkill, file, "$$");
	newXSproto(strcpy(buf, "GetScribeableSpells"), XS_Client_GetScribeableSpells, file, "$;$$");
	newXSproto(strcpy(buf, "GetScribedSpells"), XS_Client_GetScribedSpells, file, "$");
	newXSproto(strcpy(buf, "GetSkillPoints"), XS_Client_GetSkillPoints, file, "$");
	newXSproto(strcpy(buf, "GetSpellBookSlotBySpellID"), XS_Client_GetSpellBookSlotBySpellID, file, "$$");
	newXSproto(strcpy(buf, "GetSpellIDByBookSlot"), XS_Client_GetSpellIDByBookSlot, file, "$$");
	newXSproto(strcpy(buf, "GetSpentAA"), XS_Client_GetSpentAA, file, "$$");
	newXSproto(strcpy(buf, "GetStartZone"), XS_Client_GetStartZone, file, "$");
	newXSproto(strcpy(buf, "GetTargetRingX"), XS_Client_GetTargetRingX, file, "$");
	newXSproto(strcpy(buf, "GetTargetRingY"), XS_Client_GetTargetRingY, file, "$");
	newXSproto(strcpy(buf, "GetTargetRingZ"), XS_Client_GetTargetRingZ, file, "$");
	newXSproto(strcpy(buf, "GetTaskActivityDoneCount"), XS_Client_GetTaskActivityDoneCount, file, "$$$");
	newXSproto(strcpy(buf, "GetThirst"), XS_Client_GetThirst, file, "$$");
	newXSproto(strcpy(buf, "GetTotalSecondsPlayed"), XS_Client_GetTotalSecondsPlayed, file, "$");
	newXSproto(strcpy(buf, "GetWeight"), XS_Client_GetWeight, file, "$");
	newXSproto(strcpy(buf, "GoFish"), XS_Client_GoFish, file, "$");
	newXSproto(strcpy(buf, "GrantAlternateAdvancementAbility"), XS_Client_GrantAlternateAdvancementAbility, file, "$$$;$");
	newXSproto(strcpy(buf, "GuildID"), XS_Client_GuildID, file, "$");
	newXSproto(strcpy(buf, "GuildRank"), XS_Client_GuildRank, file, "$");
	newXSproto(strcpy(buf, "HasDisciplineLearned"), XS_Client_HasDisciplineLearned, file, "$$");
	newXSproto(strcpy(buf, "HasExpeditionLockout"), XS_Client_HasExpeditionLockout, file, "$$$");
	newXSproto(strcpy(buf, "HasSkill"), XS_Client_HasSkill, file, "$$");
	newXSproto(strcpy(buf, "HasSpellScribed"), XS_Client_HasSkill, file, "$$");
	newXSproto(strcpy(buf, "HasZoneFlag"), XS_Client_HasZoneFlag, file, "$$");
	newXSproto(strcpy(buf, "Hungry"), XS_Client_Hungry, file, "$");
	newXSproto(strcpy(buf, "InZone"), XS_Client_InZone, file, "$");
	newXSproto(strcpy(buf, "IncStats"), XS_Client_IncStats, file, "$$$");
	newXSproto(strcpy(buf, "IncreaseLanguageSkill"), XS_Client_IncreaseLanguageSkill, file, "$$;$");
	newXSproto(strcpy(buf, "IncreaseSkill"), XS_Client_IncreaseSkill, file, "$$;$");
	newXSproto(strcpy(buf, "IncrementAA"), XS_Client_IncrementAA, file, "$$");
	newXSproto(strcpy(buf, "IsBecomeNPC"), XS_Client_IsBecomeNPC, file, "$");
	newXSproto(strcpy(buf, "IsCrouching"), XS_Client_IsCrouching, file, "$");
	newXSproto(strcpy(buf, "IsDueling"), XS_Client_IsDueling, file, "$");
	newXSproto(strcpy(buf, "IsGrouped"), XS_Client_IsGrouped, file, "$");
	newXSproto(strcpy(buf, "IsLD"), XS_Client_IsLD, file, "$");
	newXSproto(strcpy(buf, "IsMedding"), XS_Client_IsMedding, file, "$");
	newXSproto(strcpy(buf, "IsRaidGrouped"), XS_Client_IsRaidGrouped, file, "$");
	newXSproto(strcpy(buf, "IsSitting"), XS_Client_IsSitting, file, "$");
	newXSproto(strcpy(buf, "IsStanding"), XS_Client_IsStanding, file, "$");
	newXSproto(strcpy(buf, "IsTaskActive"), XS_Client_IsTaskActive, file, "$$");
	newXSproto(strcpy(buf, "IsTaskActivityActive"), XS_Client_IsTaskActivityActive, file, "$$$");
	newXSproto(strcpy(buf, "IsTaskCompleted"), XS_Client_IsTaskCompleted, file, "$$");
	newXSproto(strcpy(buf, "KeyRingAdd"), XS_Client_KeyRingAdd, file, "$$");
	newXSproto(strcpy(buf, "KeyRingCheck"), XS_Client_KeyRingCheck, file, "$$");
	newXSproto(strcpy(buf, "Kick"), XS_Client_Kick, file, "$");
	newXSproto(strcpy(buf, "LearnDisciplines"), XS_Client_LearnDisciplines, file, "$$$");
	newXSproto(strcpy(buf, "LearnRecipe"), XS_Client_LearnRecipe, file, "$$");
	newXSproto(strcpy(buf, "LeaveGroup"), XS_Client_LeaveGroup, file, "$");
	newXSproto(strcpy(buf, "LoadZoneFlags"), XS_Client_LoadZoneFlags, file, "$");
	newXSproto(strcpy(buf, "MarkCompassLoc"), XS_Client_MarkCompassLoc, file, "$$$$");
	newXSproto(strcpy(buf, "MaxSkill"), XS_Client_MaxSkill, file, "$$;$$");
	newXSproto(strcpy(buf, "MemSpell"), XS_Client_MemSpell, file, "$$$;$");
	newXSproto(strcpy(buf, "MemmedCount"), XS_Client_MemmedCount, file, "$");
	newXSproto(strcpy(buf, "MovePC"), XS_Client_MovePC, file, "$$$$$$");
	newXSproto(strcpy(buf, "MovePCDynamicZone"), XS_Client_MovePCDynamicZone, file, "$$;$$");
	newXSproto(strcpy(buf, "MovePCInstance"), XS_Client_MovePCInstance, file, "$$$$$$$");
	newXSproto(strcpy(buf, "MoveZone"), XS_Client_MoveZone, file, "$$");
	newXSproto(strcpy(buf, "MoveZoneGroup"), XS_Client_MoveZoneGroup, file, "$$");
	newXSproto(strcpy(buf, "MoveZoneInstance"), XS_Client_MoveZoneInstance, file, "$$");
	newXSproto(strcpy(buf, "MoveZoneInstanceGroup"), XS_Client_MoveZoneInstanceGroup, file, "$$");
	newXSproto(strcpy(buf, "MoveZoneInstanceRaid"), XS_Client_MoveZoneInstanceRaid, file, "$$");
	newXSproto(strcpy(buf, "MoveZoneRaid"), XS_Client_MoveZoneRaid, file, "$$");
	newXSproto(strcpy(buf, "NPCSpawn"), XS_Client_NPCSpawn, file, "$$$;$");
	newXSproto(strcpy(buf, "NotifyNewTitlesAvailable"), XS_Client_NotifyNewTitlesAvailable, file, "$");
	newXSproto(strcpy(buf, "NukeItem"), XS_Client_NukeItem, file, "$$;$");
	newXSproto(strcpy(buf, "OpenLFGuildWindow"), XS_Client_OpenLFGuildWindow, file, "$");
	newXSproto(strcpy(buf, "PlayMP3"), XS_Client_PlayMP3, file, "$;$");
	newXSproto(strcpy(buf, "Popup2"), XS_Client_Popup2, file, "$$$;$$$$$$$");
	newXSproto(strcpy(buf, "QuestReward"), XS_Client_QuestReward, file, "$$;$$$$$$$");
	newXSproto(strcpy(buf, "ReadBook"), XS_Client_ReadBook, file, "$$$");
	newXSproto(strcpy(buf, "ReadBookByName"), XS_Client_ReadBookByName, file, "$$$");
	newXSproto(strcpy(buf, "RefundAA"), XS_Client_RefundAA, file, "$$");
	newXSproto(strcpy(buf, "RemoveAllExpeditionLockouts"), XS_Client_RemoveAllExpeditionLockouts, file, "$;$");
	newXSproto(strcpy(buf, "RemoveExpeditionLockout"), XS_Client_RemoveExpeditionLockout, file, "$$$");
	newXSproto(strcpy(buf, "RemoveItem"), XS_Client_RemoveItem, file, "$$;$");
	newXSproto(strcpy(buf, "RemoveLDoNLoss"), XS_Client_RemoveLDoNLoss, file, "$$");
	newXSproto(strcpy(buf, "RemoveLDoNWin"), XS_Client_RemoveLDoNWin, file, "$$");
	newXSproto(strcpy(buf, "RemoveNoRent"), XS_Client_RemoveNoRent, file, "$");
	newXSproto(strcpy(buf, "ResetAA"), XS_Client_ResetAA, file, "$");
	newXSproto(strcpy(buf, "ResetAllDisciplineTimers"), XS_Client_ResetAllDisciplineTimers, file, "$");
	newXSproto(strcpy(buf, "ResetAllCastbarCooldowns"), XS_Client_ResetAllCastbarCooldowns, file, "$");
	newXSproto(strcpy(buf, "ResetCastbarCooldownBySlot"), XS_Client_ResetCastbarCooldownBySlot, file, "$$");
	newXSproto(strcpy(buf, "ResetCastbarCooldownBySpellID"), XS_Client_ResetCastbarCooldownBySpellID, file, "$$");
	newXSproto(strcpy(buf, "ResetDisciplineTimer"), XS_Client_ResetDisciplineTimer, file, "$$");
	newXSproto(strcpy(buf, "ResetTrade"), XS_Client_ResetTrade, file, "$");
	newXSproto(strcpy(buf, "Save"), XS_Client_Save, file, "$$");
	newXSproto(strcpy(buf, "SaveBackup"), XS_Client_SaveBackup, file, "$");
	newXSproto(strcpy(buf, "ScribeSpell"), XS_Client_ScribeSpell, file, "$$$;$");
	newXSproto(strcpy(buf, "ScribeSpells"), XS_Client_ScribeSpells, file, "$$$");
	newXSproto(strcpy(buf, "SendColoredText"), XS_Client_SendColoredText, file, "$$$");
	newXSproto(strcpy(buf, "SendMarqueeMessage"), XS_Client_SendMarqueeMessage, file, "$$$$$$$");
	newXSproto(strcpy(buf, "SendOPTranslocateConfirm"), XS_Client_SendOPTranslocateConfirm, file, "$$$");
	newXSproto(strcpy(buf, "SendSound"), XS_Client_SendSound, file, "$");
	newXSproto(strcpy(buf, "SendSpellAnim"), XS_Client_SendSpellAnim, file, "$$$");
	newXSproto(strcpy(buf, "SendTargetCommand"), XS_Client_SendTargetCommand, file, "$$");
	newXSproto(strcpy(buf, "SendToGuildHall"), XS_Client_SendToGuildHall, file, "$");
	newXSproto(strcpy(buf, "SendToInstance"), XS_Client_SendToInstance, file, "$$$$$$$$$$");
	newXSproto(strcpy(buf, "SendWebLink"), XS_Client_SendWebLink, file, "$:$");
	newXSproto(strcpy(buf, "SendZoneFlagInfo"), XS_Client_SendZoneFlagInfo, file, "$$");
	newXSproto(strcpy(buf, "SetAAEXPModifier"), XS_Client_SetAAEXPModifier, file, "$$$");
	newXSproto(strcpy(buf, "SetAAPoints"), XS_Client_SetAAPoints, file, "$$");
	newXSproto(strcpy(buf, "SetAATitle"), XS_Client_SetAATitle, file, "$$;$");
	newXSproto(strcpy(buf, "SetAFK"), XS_Client_SetAFK, file, "$$");
	newXSproto(strcpy(buf, "SetAccountFlag"), XS_Client_SetAccountFlag, file, "$$");
	newXSproto(strcpy(buf, "SetAlternateCurrencyValue"), XS_Client_SetAlternateCurrencyValue, file, "$$$");
	newXSproto(strcpy(buf, "SetAnon"), XS_Client_SetAnon, file, "$$");
	newXSproto(strcpy(buf, "SetBaseClass"), XS_Client_SetBaseClass, file, "$$");
	newXSproto(strcpy(buf, "SetBaseGender"), XS_Client_SetBaseGender, file, "$$");
	newXSproto(strcpy(buf, "SetBaseRace"), XS_Client_SetBaseRace, file, "$$");
	newXSproto(strcpy(buf, "SetBecomeNPC"), XS_Client_SetBecomeNPC, file, "$$");
	newXSproto(strcpy(buf, "SetBecomeNPCLevel"), XS_Client_SetBecomeNPCLevel, file, "$$");
	newXSproto(strcpy(buf, "SetBindPoint"), XS_Client_SetBindPoint, file, "$;$$$$$$");
	newXSproto(strcpy(buf, "SetClientMaxLevel"), XS_Client_SetClientMaxLevel, file, "$$");
	newXSproto(strcpy(buf, "SetConsumption"), XS_Client_SetConsumption, file, "$$$");
	newXSproto(strcpy(buf, "SetCustomItemData"), XS_Client_SetCustomItemData, file, "$$$$");
	newXSproto(strcpy(buf, "SetDeity"), XS_Client_SetDeity, file, "$$");
	newXSproto(strcpy(buf, "SetDuelTarget"), XS_Client_SetDuelTarget, file, "$$");
	newXSproto(strcpy(buf, "SetDueling"), XS_Client_SetDueling, file, "$$");
	newXSproto(strcpy(buf, "SetEXP"), XS_Client_SetEXP, file, "$$$;$");
	newXSproto(strcpy(buf, "SetEXPModifier"), XS_Client_SetEXPModifier, file, "$$$");
	newXSproto(strcpy(buf, "SetEbonCrystals"), XS_Client_SetEbonCrystals, file, "$$");
	newXSproto(strcpy(buf, "SetEndurance"), XS_Client_SetEndurance, file, "$$");
	newXSproto(strcpy(buf, "SetEnvironmentDamageModifier"), XS_Client_SetEnvironmentDamageModifier, file, "$$");
	newXSproto(strcpy(buf, "SetFactionLevel"), XS_Client_SetFactionLevel, file, "$$$$$$");
	newXSproto(strcpy(buf, "SetFactionLevel2"), XS_Client_SetFactionLevel2, file, "$$$$$$$");
	newXSproto(strcpy(buf, "SetFeigned"), XS_Client_SetFeigned, file, "$$");
	newXSproto(strcpy(buf, "SetGM"), XS_Client_SetGM, file, "$$");
	newXSproto(strcpy(buf, "SetGMStatus"), XS_Client_SetGMStatus, file, "$$");
	newXSproto(strcpy(buf, "SetHideMe"), XS_Client_SetHideMe, file, "$$");
	newXSproto(strcpy(buf, "SetHorseId"), XS_Client_SetHorseId, file, "$$");
	newXSproto(strcpy(buf, "SetHunger"), XS_Client_SetHunger, file, "$$");
	newXSproto(strcpy(buf, "SetIPExemption"), XS_Client_SetIPExemption, file, "$$");
	newXSproto(strcpy(buf, "SetInvulnerableEnvironmentDamage"), XS_Client_SetInvulnerableEnvironmentDamage, file, "$$");
	newXSproto(strcpy(buf, "SetLanguageSkill"), XS_Client_SetLanguageSkill, file, "$$$");
	newXSproto(strcpy(buf, "SetMaterial"), XS_Client_SetMaterial, file, "$$$");
	newXSproto(strcpy(buf, "SetPVP"), XS_Client_SetPVP, file, "$$");
	newXSproto(strcpy(buf, "SetPrimaryWeaponOrnamentation"), XS_Client_SetPrimaryWeaponOrnamentation, file, "$$");
	newXSproto(strcpy(buf, "SetRadiantCrystals"), XS_Client_SetRadiantCrystals, file, "$$");
	newXSproto(strcpy(buf, "SetSecondaryWeaponOrnamentation"), XS_Client_SetSecondaryWeaponOrnamentation, file, "$$");
	newXSproto(strcpy(buf, "SetSkill"), XS_Client_SetSkill, file, "$$$");
	newXSproto(strcpy(buf, "SetSkillPoints"), XS_Client_SetSkillPoints, file, "$$");
	newXSproto(strcpy(buf, "SetStartZone"), XS_Client_SetStartZone, file, "$$;$$$$");
	newXSproto(strcpy(buf, "SetStats"), XS_Client_SetStats, file, "$$$");
	newXSproto(strcpy(buf, "SetThirst"), XS_Client_SetThirst, file, "$$");
	newXSproto(strcpy(buf, "SetTint"), XS_Client_SetTint, file, "$$$");
	newXSproto(strcpy(buf, "SetTitleSuffix"), XS_Client_SetTitleSuffix, file, "$$;$");
	newXSproto(strcpy(buf, "SetZoneFlag"), XS_Client_SetZoneFlag, file, "$$");
	newXSproto(strcpy(buf, "SilentMessage"), XS_Client_SilentMessage, file, "$$");
	newXSproto(strcpy(buf, "Sit"), XS_Client_Sit, file, "$");
	newXSproto(strcpy(buf, "SlotConvert2"), XS_Client_SlotConvert2, file, "$$");
	newXSproto(strcpy(buf, "Stand"), XS_Client_Stand, file, "$");
	newXSproto(strcpy(buf, "SummonBaggedItems"), XS_Client_SummonBaggedItems, file, "$$$");
	newXSproto(strcpy(buf, "SummonItem"), XS_Client_SummonItem, file, "$$;$$$$$$$$");
	newXSproto(strcpy(buf, "TGB"), XS_Client_TGB, file, "$");
	newXSproto(strcpy(buf, "TakeMoneyFromPP"), XS_Client_TakeMoneyFromPP, file, "$$;$");
	newXSproto(strcpy(buf, "TakePlatinum"), XS_Client_TakePlatinum, file, "$$;$");
	newXSproto(strcpy(buf, "Thirsty"), XS_Client_Thirsty, file, "$");
	newXSproto(strcpy(buf, "TrainDiscBySpellID"), XS_Client_TrainDiscBySpellID, file, "$$");
	newXSproto(strcpy(buf, "UnFreeze"), XS_Client_UnFreeze, file, "$");
	newXSproto(strcpy(buf, "Undye"), XS_Client_Undye, file, "$");
	newXSproto(strcpy(buf, "UnmemSpell"), XS_Client_UnmemSpell, file, "$$;$");
	newXSproto(strcpy(buf, "UnmemSpellAll"), XS_Client_UnmemSpellAll, file, "$;$");
	newXSproto(strcpy(buf, "UnmemSpellBySpellID"), XS_Client_UnmemSpellBySpellID, file, "$$");
	newXSproto(strcpy(buf, "UnscribeSpell"), XS_Client_UnscribeSpell, file, "$$;$");
	newXSproto(strcpy(buf, "UnscribeSpellAll"), XS_Client_UnscribeSpellAll, file, "$;$");
	newXSproto(strcpy(buf, "UnscribeSpellBySpellID"), XS_Client_UnscribeSpellBySpellID, file, "$$;$");
	newXSproto(strcpy(buf, "UntrainDisc"), XS_Client_UntrainDisc, file, "$$;$");
	newXSproto(strcpy(buf, "UntrainDiscAll"), XS_Client_UntrainDiscAll, file, "$;$");
	newXSproto(strcpy(buf, "UntrainDiscBySpellID"), XS_Client_UntrainDiscBySpellID, file, "$$;$");
	newXSproto(strcpy(buf, "UpdateAdmin"), XS_Client_UpdateAdmin, file, "$;$");
	newXSproto(strcpy(buf, "UpdateGroupAAs"), XS_Client_UpdateGroupAAs, file, "$$$");
	newXSproto(strcpy(buf, "UpdateLDoNPoints"), XS_Client_UpdateLDoNPoints, file, "$$$");
	newXSproto(strcpy(buf, "UpdateTaskActivity"), XS_Client_UpdateTaskActivity, file, "$$$$;$");
	newXSproto(strcpy(buf, "UpdateWho"), XS_Client_UpdateWho, file, "$;$");
	newXSproto(strcpy(buf, "UseDiscipline"), XS_Client_UseDiscipline, file, "$$$");
	newXSproto(strcpy(buf, "WorldKick"), XS_Client_WorldKick, file, "$");
	XSRETURN_YES;
}

#endif //EMBPERL_XS_CLASSES
