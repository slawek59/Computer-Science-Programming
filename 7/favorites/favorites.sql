SELECT * FROM shows;

UPDATE shows SET title = "Brooklyn Nine-Nine" WHERE title LIKE "b99";
UPDATE shows SET title = "Game of Thrones" WHERE title LIKE "%Thrones%" OR title LIKE "got";
UPDATE shows SET title = "Grey’s Anatomy" WHERE title LIKE "%anatomy%";
UPDATE shows SET title = "It’s Always Sunny in Philadelphia" WHERE title LIKE "%sunny%";
UPDATE shows SET title = "Parks and Recreation" WHERE title LIKE "parks%";
UPDATE shows SET title = "The Office" WHERE title LIKE "%office%";
UPDATE shows SET title = "Avatar: The Last Airbender" WHERE title LIKE "%avatar%";

UPDATE shows SET title = "Brooklyn Nine-Nine" WHERE title LIKE "%b99%" OR title LIKE "brooklyn%";
UPDATE shows SET title = "Sherlock" WHERE title LIKE "%sherlock%";

UPDATE shows SET title = "Billions" WHERE title LIKE "%billions%";
UPDATE shows SET title = "Criminal Minds" WHERE title LIKE "%criminal minds%";

SELECT * FROM shows ORDER BY title ASC;
