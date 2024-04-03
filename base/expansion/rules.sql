source 0-classic/rules.sql;
source 1-kunark/rules.sql;
source 2-velious/rules.sql;
source 3-luclin/rules.sql;
#source 4-pop/rules.sql;
#source 5-loy/rules.sql;
#source 6-ldon/rules.sql;
#source 7-god/rules.sql;
#source 8-oow/rules.sql;
#source 9-don/rules.sql;
#source 10-dodh/rules.sql;
#source 11-por/rules.sql;
#source 12-tss/rules.sql;
#source 13-tbs/rules.sql;
#source 14-sof/rules.sql;
#source 15-sod/rules.sql;
#source 16-uf/rules.sql;
#source 17-hot/rules.sql;
#source 18-voa/rules.sql;
#source 19-rof/rules.sql;

# Jamfest Overrides

UPDATE rule_values SET rule_value='This is an early alpha of jamfest. Currently on Luclin, #opt in to cool commands to speed things up. Check out https://jamfesteq.com for patcher and intro. Expect characters to be deleted for beta.' WHERE rule_name='World:MOTD';

# Gear left on Corpses
UPDATE rule_values SET rule_value='false' WHERE rule_name='Character:LeaveCorpses';
UPDATE rule_values SET rule_value='true' WHERE rule_name='Character:LeaveNakedCorpses';

# Disable Server-Wide OOC Chat
UPDATE rule_values SET rule_value='true' WHERE rule_name='Chat:ServerWideOOC';

# Disable Server-Wide Auction Chat
UPDATE rule_values SET rule_value='true' WHERE rule_name='Chat:ServerWideAuction';

# OoC regen
UPDATE rule_values SET rule_value='true' WHERE rule_name='Character:RestRegenEnabled';
UPDATE rule_values SET rule_value='true' WHERE rule_name='Character:RestRegenEndurance';

UPDATE rule_values SET rule_value='false' WHERE rule_name='Character:UseOldClassExpPenalties';
UPDATE rule_values SET rule_value='false' WHERE rule_name='Character:UseOldRaceExpPenalties';

# Override classic spell file
UPDATE rule_values SET rule_value='false' WHERE rule_name='Character:UseOldRaceRezEffects';

UPDATE rule_values SET rule_value='false' WHERE rule_name='Character:UseRaceClassExpBonuses';

UPDATE rule_values SET rule_value='true' WHERE rule_name='World:EnableReturnHomeButton';

UPDATE rule_values SET rule_value='2' WHERE rule_name='Character:ShowExpValues';
UPDATE rule_values SET rule_value='0' WHERE rule_name='Zone:HotZoneBonus';
UPDATE rule_values SET rule_value='false' WHERE rule_name='Zone:LevelBasedEXPMods';
UPDATE rule_values SET rule_value='true' WHERE rule_name='Combat:EXPFromDmgShield';
UPDATE rule_values SET rule_value='true' WHERE rule_name='Character:HealOnLevel';

UPDATE rule_values SET rule_value='false' WHERE rule_name='Combat:FleeGray';
UPDATE rule_values SET rule_value='0' WHERE rule_name='Combat:FleeHPRatio';

UPDATE rule_values SET rule_value='false' WHERE rule_name='Character:UnmemSpellsOnDeath';

UPDATE rule_values SET rule_value='true' WHERE rule_name='Character:AllowMQTarget';

UPDATE rule_values SET rule_value='true' WHERE rule_name='Spells:AlwaysSendTargetsBuffs';
UPDATE rule_values SET rule_value='true' WHERE rule_name='Spells:UseSpellImpliedTargeting';

UPDATE rule_values SET rule_value='12' WHERE rule_name='Character:RestRegenTimeToActivate';
UPDATE rule_values SET rule_value='24' WHERE rule_name='Character:RestRegenRaidTimeToActivate';
UPDATE rule_values SET rule_value='true' WHERE rule_name='HotReload:QuestsAutoReloadGlobalScripts';

UPDATE rule_values SET rule_value='5' WHERE rule_name='NPC:OOCRegen';

UPDATE rule_values SET rule_value='true' WHERE rule_name='Zone:QuestsReloadOnBootup';

Update rule_values SET rule_value='false' WHERE rule_name='Combat:MeleePush';
Update rule_values SET rule_value='false' WHERE rule_name='Spells:NPCSpellPush';

UPDATE rule_values SET rule_value='1.0' WHERE rule_name='Character:AAExpMultiplier';
UPDATE rule_values SET rule_value='1.0' WHERE rule_name='Character:ExpMultiplier';


UPDATE rule_values SET rule_value='0' WHERE rule_name='NPC:StartEnrageValue';