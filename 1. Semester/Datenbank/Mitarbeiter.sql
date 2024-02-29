-- Tabelle abteilung erstellen
create table abteilung ( 
 abteilung_id Integer NOT NULL, 
 bezeichnung Varchar2 (255), 
 primary key (abteilung_id) );
-- Tabelle projekt erstellen
create table projekt ( 
 projekt_id Integer NOT NULL, 
 mitarbeiter_id Integer, 
 inhalt Varchar2 (255), 
 primary key (projekt_id) );
-- Tabelle mitarbeiter erstellen
create table mitarbeiter ( 
 mitarbeiter_id Integer NOT NULL, 
 abteilung_id Integer, 
 name Varchar2 (255), 
 vorname Varchar2 (255), 
 strasse Varchar2 (255), 
 ort Varchar2 (255), 
 primary key (mitarbeiter_id) );
-- FK Constraint zu Tabelle Mitarbeiter hinzufügen
alter table mitarbeiter 
 add foreign key (abteilung_id) 
 references abteilung (abteilung_id) on delete set null;
-- FK Constraint zu Tabelle Projekt hinzufügen
alter table projekt 
 add foreign key (mitarbeiter_id)
 references mitarbeiter (mitarbeiter_id) on delete set null;
 
-- Datensätze in einem Statement in Tabelle abteilung einfügen (Oracle)
insert all
 into abteilung values (1, 'Informatik')
 into abteilung values (2, 'Wirtschaftsinformatik')
 into abteilung values (3, 'Informationsmanagement')
 into abteilung values (4, 'IT')
 select * from dual;
 
-- Datensätze in einem Statement in Tabelle mitarbeiter einfügen (Oracle)
insert all
 into mitarbeiter 
values (1, 1, 'Mayer', 'Christa', 'Taborstr 22', 'Wien')
 into mitarbeiter 
values (2, 1, 'Kernegger', 'Rene', 'Baumthal 34', 'Kirchberg am Wechsel')
 into mitarbeiter 
values (3, 2, 'Zenz', 'Markus', 'Hauptstrasse 85', 'Wimpassing')
 into mitarbeiter 
values (4, 3, 'Popp', 'Karin', 'Römerweg 300', 'Winzendorf')
 into mitarbeiter 
values (5, 4, 'Vatter', 'Elisabeth', 'Am Graben 5', 'Wien')
 select * from dual;
 
-- Datensätze in einem Statement in Tabelle projekt einfügen (Oracle)
insert all
into projekt values (1, 1, 'SW Test')
into projekt values (2, 2, 'Datenintegration')
into projekt values (3, 5, 'Datenmodellierung')
into projekt values (4, 1, 'Analyse')
into projekt values (5, null, 'Datawarehouse')
select * from dual;

select * from abteilung;
select * from mitarbeiter;
select * from projekt;

drop table abteilung cascade constraints;
drop table mitarbeiter cascade constraints;
drop table projekt;
