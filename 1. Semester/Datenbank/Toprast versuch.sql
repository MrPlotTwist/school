CREATE TABLE orte (
plz int primary key CONSTRAINT ch_plz CHECK (plz BETWEEN 1000 and 9999),
ort VARCHAR2(50) not null
);

CREATE TABLE adressen (
addr_id int primary key not null,
strasse VARCHAR2(50) not null,
ort VARCHAR2(50),
hausnummer VARCHAR2(50) null,
plz int NOT NULL CONSTRAINT fk_plz REFERENCES orte (plz));

--SELECT * FROM adressen;

CREATE TABLE filialen (
f_id int not null,
"uid" int null,
name VARCHAR2(50) not null,
telefon int null,
fax int null,
fk_addr_id int not null,
geschlossen char(1) default 0 not null,
PRIMARY KEY (f_id),
CONSTRAINT fk_filialen_adressen
  FOREIGN KEY (fk_addr_id) REFERENCES adressen (addr_id),
CONSTRAINT chk_filialen_geschlossen CHECK (geschlossen IN (1,0))
);

SELECT * FROM filialen;

CREATE TABLE personen (
pers_id INT NOT NULL,
vorname VARCHAR(45) NULL,
nachname VARCHAR(45) NULL,
geschlecht CHAR(1),
fk_addr_id INT NULL,
PRIMARY KEY (pers_id),
CONSTRAINT ck_personen_geschlecht
CHECK (geschlecht IN("m","w")),
CONSTRAINT fk_personen_adressen
FOREIGN KEY (fk_addr_id)
REFERENCES adressen (addr_id)
ON DELETE SET NULL);


CREATE TABLE kunden (
pers_id int not null,
kundennummer int not null unique,
PRIMARY KEY (fk_pers_id),
CONSTRAINT fk_kunden_personen
  FOREIGN KEY (fk_pers_id) REFERENCES personen (pers_id)
  ON DELETE CASCADE
);

CREATE TABLE mitarbeiter (
pers_id int not null,
mitarbeiternummer int not null unique,
svn int not null,
geburtsdatum DATE not null,
eintrittsdatum DATE not null,
austrittsdatum DATE null,
PRIMARY KEY (fk_pers_id),
CONSTRAINT fk_kunden_personen
  FOREIGN KEY (fk_pers_id) REFERENCES personen (pers_id)
  ON DELETE CASCADE
);

--alter session set current_schema = toprast;
