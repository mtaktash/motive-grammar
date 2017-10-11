#encoding "utf-8"

Who -> Noun;      // используем слова из статьи "персона"
Consuming -> Verb; // любой глагол
Drink -> Noun<kwtype="алкоголь">;                // используем слова из статьи "алкоголь"

//Drinking -> Who interp (Drinking.Who)
//        Consuming interp (Drinking.Consuming)
//        Drink interp (Drinking.Drink);



Situ -> Noun<kwtype=situ>;
PassiveDrinking -> Situ interp (PassiveDrinking.Situation);

