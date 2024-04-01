# Destruction Client-Based Expansion Setting
UPDATE rule_values SET rule_value='15' WHERE rule_name='Expansion:CurrentExpansion';
UPDATE rule_values SET rule_value='32767' WHERE rule_name='World:CharacterSelectExpansionSettings';
UPDATE rule_values SET rule_value='32767' WHERE rule_name='World:ExpansionSettings';

UPDATE rule_values SET rule_value='85' WHERE rule_name='Character:MaxExpLevel';
UPDATE rule_values SET rule_value='85' WHERE rule_name='Character:MaxLevel';