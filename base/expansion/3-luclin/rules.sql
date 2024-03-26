# This adjusts rules for luclin expansion
UPDATE rule_values SET rule_value='3' WHERE rule_name='Expansion:CurrentExpansion';

# Luclin Client-Based Expansion Setting
UPDATE rule_values SET rule_value='4' WHERE rule_name='World:ExpansionSettings';

# Wizard Innate Criticals
UPDATE rule_values SET rule_value='12' WHERE rule_name='Spells:WizCritLevel';