UPDATE npc_types SET aggroradius = 25, assistradius = 0 where aggroradius > 0;
# Keefe from 15 to 0
UPDATE spawn2 SET min_expansion = 0 WHERE spawngroupid = 148650;
# Iason from 15 to 0
UPDATE spawn2 SET min_expansion = 0 WHERE spawngroupid = 110163;

# 8 is 86+
UPDATE global_loot SET enabled=1, min_expansion = 0 WHERE id IN (1,2,3,4,5,6,7);

UPDATE loottable_entries SET multiplier = 5, probability = 10 WHERE loottable_id IN (110209, 110210, 110211, 110212, 110213, 110214, 110215, 110216);