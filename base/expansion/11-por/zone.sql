# all nro (34) connections now go to northro (392)
UPDATE zone_points SET max_expansion = 10 WHERE id IN (379, 575, 639, 692, 694);
REPLACE INTO `zone_points` (`buffer`, `client_version_mask`, `content_flags`, `content_flags_disabled`, `heading`, `height`, `id`, `is_virtual`, `max_expansion`, `min_expansion`, `number`, `target_heading`, `target_instance`, `target_x`, `target_y`, `target_z`, `target_zone_id`, `version`, `width`, `x`, `y`, `z`, `zone`, `zoneinst`) VALUES
(0, 4294967295, NULL, NULL, 0, 0, 4520, 0, 11, -1, 11, 260, 0, 207, 4154, -27, 392, 0, 0, -670, -1200, -50, 'freporte', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4521, 0, 11, -1, 1, 385, 0, 2903, 2604, 3.13, 392, 0, 0, -105, -2462, 3.13, 'ecommons', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4522, 0, 11, -1, 9, 145, 0, -840, 810, -3, 392, 0, 0, -20339.3, 3932.79, -33.61, 'iceclad', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4523, 0, 11, -1, 1, 0, 0, 395.4, -1824.3, 12.4, 392, 0, 0, 0, 0, 0, 'oasis', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4524, 0, 11, -1, 11, 243.50, 0, -1269, 9669.85, 23.12, 392, 0, 0, -670, -1200, -50, 'freporte', 0);

# UPDATE zone SET max_expansion = 10 WHERE short_name = 'nro';
# UPDATE zone SET min_expansion = 11 WHERE short_name = 'northro';
# spells are handled in global/spells/547.lua etc
# UPDATE spells_new SET teleport_zone = 'northro' WHERE id IN (547, 567, 1373, 2282, 4177);

# all sro (35) connections now go to southro (393)
UPDATE zone_points SET max_expansion = 10 WHERE id IN (693, 640);
REPLACE INTO `zone_points` (`buffer`, `client_version_mask`, `content_flags`, `content_flags_disabled`, `heading`, `height`, `id`, `is_virtual`, `max_expansion`, `min_expansion`, `number`, `target_heading`, `target_instance`, `target_x`, `target_y`, `target_z`, `target_zone_id`, `version`, `width`, `x`, `y`, `z`, `zone`, `zoneinst`) VALUES
(0, 4294967295, NULL, NULL, 0, 0, 4525, 0, 11, -1, 2, 256, 0, 95.6, 1530, 7, 393, 0, 0, 255, -1876, 5, 'oasis', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4526, 0, 11, -1, 1, 392, 0, 1098, -3203, -21, 393, 0, 0, 1140.77, 2569.11, -24.78, 'innothule', 0);

# all commons (21) connections now go to commonlands (408)
UPDATE zone_points SET max_expansion = 10 WHERE id IN (801, 49, 41);
REPLACE INTO `zone_points` (`buffer`, `client_version_mask`, `content_flags`, `content_flags_disabled`, `heading`, `height`, `id`, `is_virtual`, `max_expansion`, `min_expansion`, `number`, `target_heading`, `target_instance`, `target_x`, `target_y`, `target_z`, `target_zone_id`, `version`, `width`, `x`, `y`, `z`, `zone`, `zoneinst`) VALUES
(0, 4294967295, NULL, NULL, 0, 0, 4527, 0, 11, -1, 1, 384.75, 0, 1026.41, -1156.17, 44.69, 408, 0, 0, 35.22, -75.27, 3.75, 'befallen', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4528, 0, 11, -1, 2, 130, 0, -1475, 10.3, -51, 408, 0, 0, 5050, 515, -42, 'ecommons', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4529, 0, 11, -1, 3, 259, 0, 3669.36, 1192.14, 40.34, 408, 0, 0, -1089, 1464, -48, 'kithicor', 0);

# all freporte (10) connections now go to freeporteast (382)
UPDATE zone_points SET max_expansion = 10 WHERE id IN (1309, 1294, 1173, 1172, 1171, 1170, 1169, 1168, 1167, 1166, 1165, 1164, 1163, 686, 390, 386, 385);
REPLACE INTO `zone_points` (`buffer`, `client_version_mask`, `content_flags`, `content_flags_disabled`, `heading`, `height`, `id`, `is_virtual`, `max_expansion`, `min_expansion`, `number`, `target_heading`, `target_instance`, `target_x`, `target_y`, `target_z`, `target_zone_id`, `version`, `width`, `x`, `y`, `z`, `zone`, `zoneinst`) VALUES
(0, 4294967295, NULL, NULL, 0, 0, 4530, 0, 11, -1, 2, 256, 0, -944, -169, -64, 382, 0, 0, 0, 0, 0, 'veeshan', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4531, 0, 11, -1, 2, 462, 0, -950, -14, -52, 382, 0, 0, 0, 0, 0, 'timorous', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4532, 0, 11, -1, 12, 462, 0, -1570, -25, 20, 382, 0, 0, 0, 0, 0, 'airplane', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4533, 0, 11, -1, 11, 462, 0, -1570, -25, 20, 382, 0, 0, 0, 0, 0, 'airplane', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4534, 0, 11, -1, 10, 462, 0, -1570, -25, 20, 382, 0, 0, 0, 0, 0, 'airplane', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4535, 0, 11, -1, 9, 462, 0, -1570, -25, 20, 382, 0, 0, 0, 0, 0, 'airplane', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4536, 0, 11, -1, 8, 462, 0, -1570, -25, 20, 382, 0, 0, 0, 0, 0, 'airplane', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4537, 0, 11, -1, 7, 462, 0, -1570, -25, 20, 382, 0, 0, 0, 0, 0, 'airplane', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4538, 0, 11, -1, 6, 462, 0, -1570, -25, 20, 382, 0, 0, 0, 0, 0, 'airplane', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4539, 0, 11, -1, 5, 462, 0, -1570, -25, 20, 382, 0, 0, 0, 0, 0, 'airplane', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4540, 0, 11, -1, 4, 462, 0, -1570, -25, 20, 382, 0, 0, 0, 0, 0, 'airplane', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4541, 0, 11, -1, 3, 462, 0, -1570, -25, 20, 382, 0, 0, 0, 0, 0, 'airplane', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4542, 0, 11, -1, 1, 462, 0, -1570, -25, 20, 382, 0, 0, 0, 0, 0, 'airplane', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4543, 0, 11, -1, 1, 1, 0, -648, -1097, -50, 382, 0, 0, 0, 0, 0, 'nro', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4544, 0, 11, -1, 53, 462, 0, 344, -155, -94, 382, 0, 0, -1632, -740, -94, 'freportw', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4545, 0, 11, -1, 10, 260, 0, -64, 100, -24, 382, 0, 0, -622, -418, -28, 'freportw', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4546, 0, 11, -1, 9, 130, 0, -360, 448, -28, 382, 0, 0, -926, -84, -28, 'freportw', 0);

# all freportw (9) connections now go to freeportwest (383)
UPDATE zone_points SET max_expansion = 10 WHERE id IN (1343, 464, 395, 394, 393, 392, 382, 381, 380, 378, 377, 51);
REPLACE INTO `zone_points` (`buffer`, `client_version_mask`, `content_flags`, `content_flags_disabled`, `heading`, `height`, `id`, `is_virtual`, `max_expansion`, `min_expansion`, `number`, `target_heading`, `target_instance`, `target_x`, `target_y`, `target_z`, `target_zone_id`, `version`, `width`, `x`, `y`, `z`, `zone`, `zoneinst`) VALUES
(0, 4294967295, NULL, NULL, 0, 0, 4547, 0, 11, -1, 13, 510, 0, -658, 76, -32, 383, 0, 0, 0, 0, 0, 'potranquility', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4548, 0, 11, -1, 13, 510, 0, 76, -658, -32, 383, 0, 0, 0, 0, 0, 'poknowledge', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4549, 0, 11, -1, 52, 0, 0, -581, 730, -18, 383, 0, 0, -436, -6, -20, 'freportn', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4550, 0, 11, -1, 51, 320, 0, -275, 1590, 4, 383, 0, 0, 722, 372, -11, 'freportn', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4551, 0, 11, -1, 8, 250, 0, -124, 227, 999999, 383, 0, 0, 491, -415, -11, 'freportn', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4552, 0, 11, -1, 7, 126.9, 0, -700, 267, 999999, 383, 0, 0, -83, -379, -25, 'freportn', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4553, 0, 11, -1, 6, 462, 0, -682, 147, -13, 383, 0, 0, -652, 96, -39, 'freportw', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4554, 0, 11, -1, 5, 462, 0, -656, 12, -55, 383, 0, 0, -716, 149, -11, 'freportw', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4555, 0, 11, -1, 53, 196, 0, -1632, -740, -94, 383, 0, 0, 344, -155, -94, 'freporte', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4556, 0, 11, -1, 10, 462, 0, -926, -84, -28, 383, 0, 0, -360, 448, -28, 'freporte', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4557, 0, 11, -1, 9, 0, 0, -622, -418, -28, 383, 0, 0, -64, 100, -24, 'freporte', 0),
(0, 4294967295, NULL, NULL, 0, 0, 4558, 0, 11, -1, 3, 383, 0, 380.75, 0.16, -22.53, 383, 0, 0, -1600, 9, -51, 'ecommons', 0)