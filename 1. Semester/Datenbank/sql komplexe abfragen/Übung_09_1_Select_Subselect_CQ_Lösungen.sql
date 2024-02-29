/*-----------------------------------------------
Übung 9.1.1
Geben Sie nur jene Personen (Vorname, Nachname) aus, deren Gehalt über dem Durchschnitt liegt. 
Sortieren Sie absteigend nach Gehalt und aufsteigend nach Nachnamen und Vornamen.
-----------------------------------------------*/
select vorname, nachname
from person join personal using (personid)
            join gehaltsstufe using (gehaltsstufeid)
where monatsgehalt > (select avg(monatsgehalt)
                      from personal join gehaltsstufe using (gehaltsstufeid))
order by nachname, vorname;










/*-----------------------------------------------
Übung 9.1.2
Geben Sie eine Liste aller Personen aus (Vorname, Nachname), für die keine Nationalität angegeben ist. 
Sortieren Sie aufsteigend nach Nachnamen und Vornamen. (ohne Join)
-----------------------------------------------*/
select vorname, nachname
from person
where personID not in (select personID from reisepass)
order by nachname, vorname;










/*-----------------------------------------------
Übung 9.1.3
Geben Sie den Vornamen, den Nachnamen und das Alter der ältesten Person aus.
-----------------------------------------------*/
select vorname, nachname, months_between(sysdate, geburtsdatum)/12 "ALTER"
from person
where geburtsdatum = (select min(geburtsdatum) from person);









/*-----------------------------------------------
Übung 9.1.4
Geben Sie die Anzahl der Mitarbeiter des Flugpersonals und des Bodenpersonals in einer Ergebnistabelle aus.
-----------------------------------------------*/
-- als Spalten
select (select count(*) from flugpersonal) Flugpersonal, -- <-- Subselect - Anzahl Flugpersonal mit Aliasname Flugpersonal
	   (select count(*) from bodenpersonal) Bodenpersonal -- <-- Subselect - Anzahl Bodenpersonal mit Aliasname Bodenpersonal 
from dual; -- <-- Dummytabelle dual (Oracle)


-- als Zeilen
select 'Flugpersonal' Personaltyp, count(*) Anzahl from flugpersonal -- <-- Abfrage - Konstante Flugpersonal, Anzahl Flugpersonal mit Aliasname Anzahl
union
select 'Bodenpersonal', count(*) from bodenpersonal -- <-- Abfrage - Konstante Bodenpersonal, Anzahl Bodenpersonal (Aliasname nicht erfoderlich, kommt von erster Abfrage)
order by 1 desc; -- <-- Order By nach allen Mengenabfragen


