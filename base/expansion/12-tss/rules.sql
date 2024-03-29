# Spine Client-Based Expansion Setting
UPDATE rule_values SET rule_value='12' WHERE rule_name='Expansion:CurrentExpansion';
UPDATE rule_values SET rule_value='2048' WHERE rule_name='World:CharacterSelectExpansionSettings';
UPDATE rule_values SET rule_value='2048' WHERE rule_name='World:ExpansionSettings';

UPDATE rule_values SET rule_value='75' WHERE rule_name='Character:MaxExpLevel';
UPDATE rule_values SET rule_value='75' WHERE rule_name='Character:MaxLevel';