# This adjusts rules related to Dungeons
UPDATE rule_values SET rule_value='6' WHERE rule_name='Expansion:CurrentExpansion';

# Dungeons Client-Based Expansion Setting
UPDATE rule_values SET rule_value='32' WHERE rule_name='World:ExpansionSettings';