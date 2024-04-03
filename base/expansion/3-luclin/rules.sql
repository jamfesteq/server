# This adjusts rules for luclin expansion
UPDATE rule_values SET rule_value='3' WHERE rule_name='Expansion:CurrentExpansion';
UPDATE rule_values SET rule_value='7' WHERE rule_name='World:ExpansionSettings';
UPDATE rule_values SET rule_value='7' WHERE rule_name='World:CharacterSelectExpansionSettings';

# Wizard Innate Criticals
UPDATE rule_values SET rule_value='12' WHERE rule_name='Spells:WizCritLevel';

