# This adjust rules for the planes expansion
UPDATE rule_values SET rule_value='4' WHERE rule_name='Expansion:CurrentExpansion';
UPDATE rule_values SET rule_value='15' WHERE rule_name='World:CharacterSelectExpansionSettings';
UPDATE rule_values SET rule_value='15' WHERE rule_name='World:ExpansionSettings';

# Level 65 cap until Omens of War
UPDATE rule_values SET rule_value='65' WHERE rule_name='Character:MaxExpLevel';
UPDATE rule_values SET rule_value='65' WHERE rule_name='Character:MaxLevel';