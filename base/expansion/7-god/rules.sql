# This adjust rules for the Gates expansion
UPDATE rule_values SET rule_value='7' WHERE rule_name='Expansion:CurrentExpansion';

# Gates Client-Based Expansion Setting
UPDATE rule_values SET rule_value='64' WHERE rule_name='World:ExpansionSettings';