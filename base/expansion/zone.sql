# ZEM - 1.0
UPDATE zone SET zone_exp_multiplier = '1.00';

# 60 second shutdown for zones
UPDATE zone SET shutdowndelay = '60000';

UPDATE zone SET fast_regen_hp = 80 where short_name != 'potorment';