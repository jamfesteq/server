source 0-classic/rules.sql;
#source 1-kunark/rules.sql;
#source 2-velious/rules.sql;
#source 3-luclin/rules.sql;
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
