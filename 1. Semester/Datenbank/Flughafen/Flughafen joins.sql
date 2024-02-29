SELECT * from person WHERE vorname = 'Alexander' and (Nachname like 'M%' or Nachname like 'N%');
select vorname || ' ' || nachname as "Name" from person;
SELECT * FROM Gehaltsstufe WHERE monatsgehalt BETWEEN 2000 and 3000;
select * from gehaltsstufe where monatsgehalt >= 2000 and monatsgehalt <= 3000;
SELECT distinct vorname FROM person; 
SELECT gehaltsstufeID, monatsgehalt * 14 as "Jahresgehalt" FROM gehaltsstufe;
SELECT COUNT(*) FROM abteilung;
Geben Sie jene Flugzeuge der Flugzeugtyptabelle aus, deren Sitzplatzanzahl zwischen 100
und 160 Sitzplätzen liegt und die über 10.000 km weit fliegen können. (Punkte 4) 
SELECT * FROM flugzeugtyp WHERE sitzplaetze BETWEEN 100 and 160 and flugstrecke_maximal >= 10000;
Geben Sie jene Reisepassnummern aus, die mit 2 beginnen, auf 0 enden und wo mindestens
2x die Zahl 5 vorkommt.
SELECT reisepassnr FROM reisepass WHERE reisepassnr like '2%5%5%0';
. Geben Sie alle Postleitzahlen und Ortsnamen aus. Ordnen Sie die Ausgabe nach Ortsnamen
und Postleitzahl.
SELECT plz, bezeichnung FROM ort ORDER BY plz, bezeichnzung;

Geben Sie jene Personen aus, die Maier oder Mayer heißen. (überlegen Sie sich wie Sie das
in einem Statement ohne OR Operator abbilden können)

SELECT * FROM person WHERE nachname IN ('Maier','Mayer');

Geben Sie für alle Datensätze aus der Tabelle Land das Kennzeichen und die Bezeichnung
aus, die weder Österreich (Austria) noch Deutschland sind. (2 Lösungsmöglichkeiten) (Punkte
4) 

SELECT kennzeichen, bezeichnung FROM Land WHERE kennzeichen NOT IN ('AUT','GER'); 

3. Geben Sie alle Datensätze der Tabelle Gepaeck aus, in denen das Gepäck 20 kg
überschreitet. Geben Sie zusätzlich ein Feld ?Aufpreis aus, in dem für jedes Kilogramm
Übergewicht ¤ 2,50 verrechnet wird. (Punkte 6) 

SELECT gepaeck.*, (gewicht - 20) * 2.5 as "Aufpreis" FROM Gepaeck WHERE gewicht > 20;

-- Geben Sie eine Liste aller unterschiedlichen Nachnamen die mehrfach vorkommen, aus und die Häufigkeit ihres Vorkommens.
-- Ordnen Sie die Ausgabe nach der Häufigkeit ihres Vorkommens in absteigender Reihenfolge und Nachnamen in aufsteigender Reihenfolge.

SELECT nachname, COUNT(*) AS Anzahl FROM person GROUP BY nachname HAVING COUNT(nachname) > 1 ORDER BY Anzahl DESC, nachname ASC;

-- Geben Sie eine Liste aller Personen aus, die vor 1980 geboren wurden und
-- sortieren Sie die Personen nach Nachname und innerhalb des Nachnamens nach Vorname
SELECT vorname, nachname, geburtsdatum FROM person WHERE geburtsdatum < to_date('01.01.1980','dd.mm.yyyy');
ORDER BY nachname, vorname desc; 

Geben Sie alle Personen der Tabelle Person aus, die zwischen 28.2 und 6.3 Geburtstag haben.
SELECT * FROM person where to_char(geburtsdatum, 'mm.dd.') between '02.28.' and '03.06.';

-- Geben Sie das durchschnittliche Alter aller Personen aus.
select avg(trunc(months_between(sysdate,geburtsdatum)/12)) as Durchschnittsalter -- Oracle
from person;

select vorname, nachname, trunc(months_between(sysdate, geburtsdatum)/12) "Alter"
from person
where trunc(months_between(to_date('01.01.2021', 'dd.mm.yyyy'), geburtsdatum)/12) >= 65
order by 3 desc;


Geben Sie Nachname, Vorname und Reisepassnummer der Personen aus, die einen
Reisepass besitzen. Sortieren Sie aufsteigend nach Nachnamen und Vorname. (Punkte 4)

SELECT nachname, vorname, reisepassnr 
FROM person p join reisepass r ON p.personid =  r.reisepassID
ORDER BY nachname, vorname;

Geben Sie alle Personen (Vorname, Nachname) aus, die aus Österreich kommen.
Sortieren Sie aufsteigend nach Nachnamen und Vorname. (Punkte 4)

SELECT vorname, nachname FROM person pn
join reisepass rp ON pn.personid = rp.personid
join land ld on rp.landid = ld.landid
where bezeichnung = 'Österreich'
ORDER BY 2, 1;

select vorname, nachname
from person pn join reisepass rp on pn.personid = rp.personid
            join land ld on rp.landid = ld.landid
where bezeichnung = 'Österreich'
order by 2, 1;

Geben Sie die Vornamen und Nachnamen, sowie das Gehalt des Personals aus.
-- Sortieren Sie nach dem Gehalt in absteigender Reihenfolge, sowie Nachname und Vorname in aufsteigender Reihenfolge. (4 Punkte)

SELECT p.vorname, p.nachname, g.monatsgehalt FROM person p
join personal ON personal.personID = p.personID
join gehaltsstufe g ON g.gehaltsstufeID = personal.gehaltsstufeID
ORDER BY 3 desc, 2, 1;


Geben Sie ein Liste der Mitarbeiter mit Vornamen, Nachnamen, Personalnummer und Sozialversicherungsnummer aus. 
Sortieren Sie absteigend nach Nachnamen und Vornamen.

SELECT p.vorname, p.nachname, pl.personalnummer, pl.sozversnr FROM person p
join personal pl ON pl.personID = p.personID
ORDER BY p.nachname desc, p.vorname DESC;

select vorname, nachname, personalnummer, sozversnr
from person join personal on person.personid = personal.personid
order by nachname desc, vorname desc;

Geben Sie eine Liste aller (!) Personen (Vorname, Nachname) aus. 
Geben Sie in der Liste für jede Person gegebenenfalls auch die Reisepassnummer aus.

SELECT vorname, nachname, reisepassnr FROM person p
join reisepass rp ON rp.personID = p.personID;

Geben Sie eine Liste aller Personen aus (Vorname, Nachname), für die keine Nationalität angegeben ist (= Personen, die keinen Reisepass haben). 
Sortieren Sie aufsteigend nach Nachnamen und Vornamen. (Punkte 4)

SELECT vorname, nachname FROM person p 
left join reisepass rp ON rp.personID = p.personID
WHERE rp.reisepassnr is null
ORDER BY nachname, vorname;

select vorname, nachname
from person pn left join reisepass rp on pn.personid = rp.personid
where reisepassid is null
order by nachname, vorname;

Geben Sie das Durchschnittsgehalt des Flugpersonals au

SELECT AVG(monatsgehalt) FROM flugpersonal join personal using (personid)
                  join gehaltsstufe using (gehaltsstufeid);
                  

Geben Sie alle Abteilungen aus, denen keine Mitarbeiter zugeordnet sind. (2 Punkte)

SELECT bezeichnung FROM abteilung
left join bodenpersonal bl ON bl.abteilungsid = abteilung.abteilungsid
WHERE personid is null;

select bezeichnung
from abteilung ag left join bodenpersonal bl on ag.abteilungsID = bl.abteilungsID
where personid is null;

Geben Sie eine Liste aller Passagiere aus (Vorname, Nachname), die auf Flügen von ?Paris
Charles de Gaulle gebucht waren. (6 Punkte)

SELECT vorname, nachname FROM person p
join passagierliste pg ON p.personid = pg.personid
join flug ON flug.flugID = pg.flugID
join flughafen fh ON fh.flughafenID = flug.flughafen_abflug
WHERE bezeichnung = 'Paris Charles de Gaulle';

select vorname, nachname
from person join passagierliste using (personid)
            join flug using (flugid)
            join flughafen on flughafen_abflug = flughafenid
where bezeichnung = 'Paris Charles de Gaulle';
