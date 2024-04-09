# ZEM - 1.0
UPDATE zone SET zone_exp_multiplier = '1.00';

# 60 second shutdown for zones
UPDATE zone SET shutdowndelay = '60000';

UPDATE zone SET fast_regen_hp = 60 where short_name != 'potorment';
UPDATE zone SET fast_regen_mana = 60 where short_name != 'potorment';
UPDATE zone SET fast_regen_endurance = 60 where short_name != 'potorment';

UPDATE zone SET min_expansion = 10, min_status = 0 WHERE expansion = 10;
UPDATE zone SET min_expansion = 11, min_status = 0 WHERE expansion = 11;