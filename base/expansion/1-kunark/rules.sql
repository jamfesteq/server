# This adjusts rules for kunark expansion
UPDATE rule_values SET rule_value='1' WHERE rule_name='Expansion:CurrentExpansion';
UPDATE rule_values SET rule_value='1' WHERE rule_name='World:ExpansionSettings';
UPDATE rule_values SET rule_value='1' WHERE rule_name='World:CharacterSelectExpansionSettings';

# Level 60 cap until PoP
UPDATE rule_values SET rule_value='60' WHERE rule_name='Character:MaxExpLevel';
UPDATE rule_values SET rule_value='60' WHERE rule_name='Character:MaxLevel';
