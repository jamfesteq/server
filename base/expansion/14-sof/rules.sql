# Secrets Client-Based Expansion Setting
UPDATE rule_values SET rule_value='14' WHERE rule_name='Expansion:CurrentExpansion';
UPDATE rule_values SET rule_value='16383' WHERE rule_name='World:CharacterSelectExpansionSettings';
UPDATE rule_values SET rule_value='16383' WHERE rule_name='World:ExpansionSettings';

UPDATE rule_values SET rule_value='80' WHERE rule_name='Character:MaxExpLevel';
UPDATE rule_values SET rule_value='80' WHERE rule_name='Character:MaxLevel';