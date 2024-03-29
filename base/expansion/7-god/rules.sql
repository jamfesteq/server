# This adjust rules for the Gates expansion
UPDATE rule_values SET rule_value='7' WHERE rule_name='Expansion:CurrentExpansion';
UPDATE rule_values SET rule_value='64' WHERE rule_name='World:CharacterSelectExpansionSettings';
UPDATE rule_values SET rule_value='64' WHERE rule_name='World:ExpansionSettings';