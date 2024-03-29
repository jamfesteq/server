# This adjusts rules related to Legacy of ykesha
UPDATE rule_values SET rule_value='5' WHERE rule_name='Expansion:CurrentExpansion';
UPDATE rule_values SET rule_value='16' WHERE rule_name='World:CharacterSelectExpansionSettings';
UPDATE rule_values SET rule_value='16' WHERE rule_name='World:ExpansionSettings';

# Shared bank is now enabled
UPDATE rule_values SET rule_value='true' WHERE rule_name='Character:SharedBankPlat';