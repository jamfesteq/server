# This adjust rules for the Omens expansion
UPDATE rule_values SET rule_value='8' WHERE rule_name='Expansion:CurrentExpansion';
UPDATE rule_values SET rule_value='128' WHERE rule_name='World:CharacterSelectExpansionSettings';
UPDATE rule_values SET rule_value='128' WHERE rule_name='World:ExpansionSettings';

# Bard AE Nerf
UPDATE rule_values SET rule_value='false' WHERE rule_name='Spells:PreNerfBardAEDoT';

# Task System
UPDATE rule_values SET rule_value='true' WHERE rule_name='TaskSystem:EnableTaskSystem';

# Level 70 cap until The Serpent's Spine
UPDATE rule_values SET rule_value='70' WHERE rule_name='Character:MaxExpLevel';
UPDATE rule_values SET rule_value='70' WHERE rule_name='Character:MaxLevel';