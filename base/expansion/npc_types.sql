UPDATE npc_types SET aggroradius = 25, assistradius = 0 where aggroradius > 0;

UPDATE spawn2 SET min_expansion = 0 WHERE id = 148650; # Keefe from 15 to 0
UPDATE spawn2 SET min_expansion = 0 WHERE id = 110163; # Iason from 15 to 0
