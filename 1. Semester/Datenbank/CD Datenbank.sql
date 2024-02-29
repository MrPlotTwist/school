CREATE TABLE CD (
CID int primary key,
Titel VARCHAR2(50),
Erscheinungsjahr int,
VID int);

CREATE TABLE Verlag (
VID int primary key,
Name VARCHAR2(50) not null,
Straﬂe VARCHAR2(50),
Nummer int,
PLZ int);

CREATE TABLE Ort (
PLZ int primary key,
Ortsname VARCHAR2(50) not null);


CREATE TABLE Urheber (
U_ID int primary key,
Name VARCHAR2(50),
Vorname VARCHAR2(50),
Heimatland VARCHAR2(50));

CREATE TABLE Urheberschaft (
CID int,
RID int,
U_ID int,
primary key (CID, RID, U_ID));

CREATE TABLE Rolle (
RID int primary key,
Bezeichnung VARCHAR2(50));

ALTER TABLE Verlag
ADD CONSTRAINT FK_Verlag_PLZ foreign key (PLZ) references Ort (PLZ);

ALTER TABLE CD
ADD CONSTRAINT FK_CD_VID FOREIGN KEY (VID)
REFERENCES Verlag (VID);

ALTER TABLE Urheberschaft
ADD CONSTRAINT FK_UHS_CID FOREIGN KEY (CID)
REFERENCES CD (CID) ON DELETE CASCADE;

ALTER TABLE Urheberschaft
ADD CONSTRAINT FK_UHS_UID FOREIGN KEY (U_ID)
REFERENCES Urheber (U_ID) ON DELETE CASCADE;

ALTER TABLE Urheberschaft
ADD CONSTRAINT FK_UHS_RID FOREIGN KEY (RID)
REFERENCES Rolle (RID) ON DELETE CASCADE;


DROP TABLE CD;
DROP TABLE Verlag;
DROP TABLE Ort;
DROP TABLE Urheber;
DROP TABLE Urheberschaft;
DROP TABLE Rolle;

SELECT * FROM CD;





