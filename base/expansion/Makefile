EXPANSION := 11

inject:
	make expansion-$(EXPANSION)
	@echo "Overriding with custom..."
	sudo mariadb --database peq -e "source npc_types.sql"
	sudo mariadb --database peq -e "source rules.sql"
	sudo mariadb --database peq -e "source zone.sql"
	sudo mariadb --database peq -e "source pok_spell.sql"

expansion-0:
	cd 0-classic && sudo mariadb --database peq -e "source aa.sql"
	cd 0-classic && sudo mariadb --database peq -e "source content_flags.sql"
	cd 0-classic && sudo mariadb --database peq -e "source rules.sql"

expansion-1: expansion-0
	cd 1-kunark && sudo mariadb --database peq -e "source rules.sql"

expansion-2: expansion-1
	cd 2-velious && sudo mariadb --database peq -e "source rules.sql"

expansion-3: expansion-2
	cd 3-luclin && sudo mariadb --database peq -e "source rules.sql"

expansion-4: expansion-3
	cd 4-pop && sudo mariadb --database peq -e "source rules.sql"

expansion-5: expansion-4
	cd 5-loy && sudo mariadb --database peq -e "source rules.sql"

expansion-6: expansion-5
	cd 6-ldon && sudo mariadb --database peq -e "source rules.sql"

expansion-7: expansion-6
	cd 7-god && sudo mariadb --database peq -e "source rules.sql"

expansion-8: expansion-7
	cd 8-oow && sudo mariadb --database peq -e "source rules.sql"

expansion-9: expansion-8
	cd 9-don && sudo mariadb --database peq -e "source content_flags.sql"
	cd 9-don && sudo mariadb --database peq -e "source rules.sql"

expansion-10: expansion-9
	cd 10-dodh && sudo mariadb --database peq -e "source rules.sql"

expansion-11: expansion-10
	cd 11-por && sudo mariadb --database peq -e "source rules.sql"
	cd 11-por && sudo mariadb --database peq -e "source zone.sql"

expansion-12: expansion-11
	cd 12-tss && sudo mariadb --database peq -e "source rules.sql"

expansion-13: expansion-12
	cd 13-tbs && sudo mariadb --database peq -e "source rules.sql"

expansion-14: expansion-13
	cd 14-sof && sudo mariadb --database peq -e "source rules.sql"

expansion-15: expansion-14
	cd 15-sod && sudo mariadb --database peq -e "source rules.sql"

expansion-16: expansion-15
	cd 16-uf && sudo mariadb --database peq -e "source rules.sql"

expansion-17: expansion-16
	cd 17-hot && sudo mariadb --database peq -e "source rules.sql"

expansion-18: expansion-17
	cd 18-voa && sudo mariadb --database peq -e "source rules.sql"

expansion-19: expansion-18
	cd 19-rof && sudo mariadb --database peq -e "source rules.sql"