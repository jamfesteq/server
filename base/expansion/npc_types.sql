
# PoK sellers
# Disable prior versions
UPDATE spawn2 SET min_expansion = 99 WHERE spawngroupID IN (
	SELECT se.spawngroupID from spawnentry se WHERE se.npcID in (
202517,
202518,
202519,
202520,
202521,
202353,
202354,
202355,
202356,
202357,
202527,
202528,
202529,
202530,
202531,
202343,
202347,
202348,
202349,
202352,
202320,
202323,
202334,
202335,
202338,
202358,
202359,
202371,
202374,
202496,
202512,
202513,
202514,
202515,
202516,
202507,
202508,
202509,
202510,
202511,
202522,
202523,
202524,
202525,
202526,
202517,
202518,
202519,
202520,
202521,
202502,
202503,
202504,
202505,
202506,
202159,
202160,
202314,
202318,
202319,
202497,
202498,
202499,
202500,
202501
	)
);

# PoK tomes
UPDATE spawn2 SET min_expansion = 0 WHERE spawngroupID IN (
	SELECT se.spawngroupID from spawnentry se WHERE se.npcID in (
		202158,
		202308,
		202289,
		202288,
		202309,
		202155,
		202156,
		202157,
		202161,
		202310
	)
);

# PoK vendors 1-60
UPDATE spawn2 SET min_expansion = 0 WHERE spawngroupID IN (
	SELECT se.spawngroupID from spawnentry se WHERE se.npcID in (
		202189,
		202192,
		202193,
		202229,
		202233,
		202232,
		202224,
		202228,
		202227,
		202219,
		202223,
		202222,
		202469,
		202218,
		202217,
		202467,
		202213,
		202212,
		202204,
		202208,
		202207,
		202199,
		202203,
		202202,
		202194,
		202198,
		202197,
		202189,
		202193,
		202192,
		202184,
		202188,
		202187,
		202179,
		202183,
		202182,
		202174,
		202178,
		202177
	)
);

# PoK Vendors 61-70
UPDATE spawn2 SET min_expansion = 99 WHERE spawngroupID IN (
	SELECT se.spawngroupID from spawnentry se WHERE se.npcID in (
		202191,
		202231,
		202226,
		202221,
		202216,
		202211,
		202206,
		202201,
		202196,
		202191,
		202186,
		202181,
		202176
	)
);

# PoK Vendors 71-80
UPDATE spawn2 SET min_expansion = 99 WHERE spawngroupID IN (
	SELECT se.spawngroupID from spawnentry se WHERE se.npcID in (
		202190,
		202230,
		202225,
		202220,
		202215,
		202210,
		202205,
		202200,
		202195,
		202190,
		202185,
		202180,
		202175
	)
);



# lower aggro radius
UPDATE npc_types SET aggroradius = 25, assistradius = 0 where aggroradius > 0;
# Keefe from 15 to 0
UPDATE spawn2 SET min_expansion = 0 WHERE spawngroupid = 148650;
# Iason from 15 to 0
UPDATE spawn2 SET min_expansion = 0 WHERE spawngroupid = 110163;

# 8 is 86+
UPDATE global_loot SET enabled=1, min_expansion = 0 WHERE id IN (1,2,3,4,5,6,7);

UPDATE loottable_entries SET multiplier = 5, probability = 10 WHERE loottable_id IN (110209, 110210, 110211, 110212, 110213, 110214, 110215, 110216);



