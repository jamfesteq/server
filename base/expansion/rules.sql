# Jamfest Overrides

UPDATE rule_values SET rule_value='This is an early alpha of jamfest. Currently on Depths of Darkhollow, #opt in to cool commands to speed things up. Check out https://jamfesteq.com for patcher and intro. Expect characters to be deleted for beta. Guildmasters are handy, hail them.' WHERE rule_name='World:MOTD';

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

UPDATE rule_values SET rule_value='false' WHERE rule_name='Zone:QuestsReloadOnBootup';

Update rule_values SET rule_value='false' WHERE rule_name='Combat:MeleePush';
Update rule_values SET rule_value='false' WHERE rule_name='Spells:NPCSpellPush';

UPDATE rule_values SET rule_value='1.0' WHERE rule_name='Character:AAExpMultiplier';
UPDATE rule_values SET rule_value='1.0' WHERE rule_name='Character:ExpMultiplier';


UPDATE rule_values SET rule_value='0' WHERE rule_name='NPC:StartEnrageValue';

UPDATE rule_values SET rule_value='0' WHERE rule_name='Adventure:MinNumberForGroup';