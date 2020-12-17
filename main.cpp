#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Movie; // data type for movie
class MovieNode; // node for movie List
class MovieList; // list of all movies
class ActorsInMovie; // list for all actors in movie
class Actor; // data type for actor
class ActorNode; // node for actor list
class ActorList; // list of all actors
class MoviesActedIn; // list of all movies of an actor
class Director; // data type for director
class DirectorNode; // node for director list
class DirectorList; // list of all directors
class MoviesDirected; // list of all movies directed by director
class GenreListNode; // node for type of genre
class GenreMovieNode; // node for movies under genre list
class GenreList; // list of all genres
class YearWiseListNode; // node for movies under each year
class YearWiseList; // list of all years
class RatingWiseListNode; // node for movies under each rating
class RatingWiseList; // list of all possible ratings

void parser(MovieList *mList, ActorList *aList, DirectorList *dList, GenreList *gList, YearWiseList *yList,RatingWiseList *rList);
void AddGenre(GenreList *gList, MovieNode *mNode, string genre);
void MainScreen();

void Function1SearchAndPrintActor(ActorList *aList,YearWiseList *yList, string name);
void Function2SearchCoActors(ActorList *aList, string actor_name);
void Function3UniqueCoActors(ActorList *aList,MovieList *mList,string actor_name);
void Function4PrintCoActorsOfCoActors(ActorList *aList, string actor_name);
void Function5CheckIfCoActorsOrNot(ActorList *aList, MovieList *mList, string actor_a, string actor_b);
void Function6PrintAllMoviesOfDirector(DirectorList *dList, string name);
void Function7PrintMoviesOfDirectorOfCertainGenre(GenreList *gList, string genre);
void Function8SearchAndPrintMovie(MovieList *mList, string movie_name);
void Function9PrintMoviesInGivenYear(YearWiseList *yList, int year);
void Function10PrintMoviesYearWise(YearWiseList *yList);
void Function11And13PrintMoviesOfGivenGenreRatingWise(RatingWiseList *rList, string Genre);
void Function12PrintMoviesRatingWise(RatingWiseList *rList);





class Movie
{
public:
    string movie_title;
    DirectorNode *pdirector;
    ActorsInMovie *pstart_actor;
    unsigned long int gross;
    vector<string> genre{};
    unsigned int num_voted_users;
    unsigned short int title_year;
    unsigned long int budget;
    float imdb_score;
    unsigned short int num_critic_for_reviews;
    unsigned short int duration;
    unsigned int cast_total;
    unsigned short int facenumber_in_poster;
    vector<string> plot_keywords{};
    string movie_imdb_link;
    unsigned short int num_user_for_reviews;
    string language;
    string country;
    string content_rating;
    float aspect_ratio;
    unsigned int movie_facebook_likes;
    string color;
};

class MovieNode
{
public:
    MovieNode *next;
    Movie data;
};

class MovieList
{
public:
    MovieNode *start = NULL;
    MovieNode *last = NULL;
    MovieNode *loc = NULL;
    MovieNode *pLoc = NULL;

    bool IsMovieListEmpty()
    {
        return start == NULL;
    }

    bool Search(string name) {
        loc = start;
        pLoc = NULL;
        if (IsMovieListEmpty())
            return false;
        while (loc != NULL && loc->data.movie_title.substr(0, loc->data.movie_title.length() - 2) != name) {
            pLoc = loc;
            loc = loc->next;
        }
        if (loc == NULL) {
            return false;
        } else
            return true;
    }
};

class ActorsInMovie
{
public:
    ActorNode *pdata;
    ActorsInMovie *next;
};

class Actor
{
public:
    string actor_name;
    unsigned int actor_facebook_likes = 0;
};

class ActorNode
{
public:
    Actor data;
    ActorNode *next;
    MoviesActedIn *start;
};

class ActorList
{
public:
    ActorNode *start = NULL;
    ActorNode *last = NULL;

    ActorNode *loc = NULL;
    ActorNode *pLoc = NULL;
    bool isEmpty()
    {
        return start == NULL;
    }

    bool SearchForRepetition(string name)
    {
        loc = start;
        pLoc = NULL;
        if (isEmpty())
            return false;
        while (loc != NULL && loc->data.actor_name != name)
        {
            pLoc = loc;
            loc = loc->next;
        }
        if (loc == NULL)
        {
            return false;
        }
        else
            return true;
    }
};

class MoviesActedIn
{
public:
    MovieNode *pdata;
    MoviesActedIn *next;
};

class Director
{
public:
    string director_name;
    unsigned int director_facebook_likes;
};

class DirectorNode
{
public:
    Director data;
    DirectorNode *next;
    MoviesDirected *start;
};

class DirectorList
{
public:
    DirectorNode *start = NULL;
    DirectorNode *last = NULL;
    DirectorNode *loc = NULL;
    DirectorNode *pLoc = NULL;

    bool IsDirectorListEmpty()
    {
        return start == NULL;
    }

    bool SearchForRepetition(string name)
    {
        loc = start;
        pLoc = NULL;
        if (IsDirectorListEmpty())
            return false;
        while (loc != NULL && loc->data.director_name != name)
        {
            pLoc = loc;
            loc = loc->next;
        }
        if (loc == NULL)
        {
            return false;
        }
        else
            return true;
    }
};

class MoviesDirected
{
public:
    MovieNode *pdata;
    MoviesDirected *next;
};

class GenreMovieNode{
public:
    MovieNode *pdata;
    GenreMovieNode *next;
};

class GenreListNode{
public:
    string genre_type;
    GenreListNode *next;
    GenreMovieNode *start_genre_movie;
};

class GenreList{
public:
    GenreListNode *start;
    GenreListNode *last;
    GenreListNode *loc;
    GenreListNode *ploc;
    GenreList(){
        start = NULL;
        last = NULL;
        ploc = NULL;
    }

    bool IsGenreEmpty(){
        return start == NULL;
    }

    bool SearchGenreForReptition(string GenreName){
        {
            loc = start;
            ploc = NULL;
            if (IsGenreEmpty())
                return false;
            while (loc != NULL && loc->genre_type != GenreName)
            {
                ploc = loc;
                loc = loc->next;
            }
            if (loc == NULL)
            {
                return false;
            }
            else
                return true;
        }
    }
};

class YearWiseListNode{
public:
    MovieNode *pdata;
    YearWiseListNode *next;
};

class YearWiseList{
public:
    YearWiseListNode *pstart_YearWise[102];
    int year_min = 1916;
    int max_index = 102;

    YearWiseList(){
        for(int i = 0; i<102; i++){
            pstart_YearWise[i] = NULL;
        }
    }
};

class RatingMovieNode{
public:
    MovieNode *pdata;
    RatingMovieNode *next;
};

class RatingWiseListNode{
public:
    float rating;
    RatingMovieNode *start_rating_movie;
    RatingWiseListNode *next;
};

class RatingWiseList{
public:
    RatingWiseListNode *start;
    RatingWiseListNode *last;
    RatingWiseListNode *loc ;
    RatingWiseListNode *ploc;

    RatingWiseList(){
        start = NULL;
        last = NULL;
        ploc = NULL;
        loc = NULL;
    }

    bool IsRatingWiseEmpty(){
        return start == NULL;
    }


    void SearchRatingWiseForRepetition(float Rating)
    {
        loc = start;
        ploc = NULL;
        if (!IsRatingWiseEmpty()){
            while (loc != NULL && loc->rating > Rating)
            {
                ploc = loc;
                loc = loc->next;
            }

        }
    }



    void InsertNodeRatingWise(float Rating) {
        SearchRatingWiseForRepetition(Rating);
        // cout<<TempActedIn->pdata->data.title_year<<" ";
        RatingWiseListNode *newnode = new RatingWiseListNode();
        newnode->rating = Rating;
        newnode->next = NULL;
        if(ploc == NULL){
            if (IsRatingWiseEmpty()) {
                start = newnode;
                last = newnode;
            }
            else {
                newnode->next = start;
                start = newnode;
            }
        }
        else{
            newnode->next = ploc->next;
            ploc->next = newnode;
            if (ploc == last)
                last = newnode;
        }
    }

};



// Parser fetches all the data, feed all of the data in all of the lists while taking care of conditions
void parser(MovieList *mList, ActorList *aList, DirectorList *dList, GenreList *gList, YearWiseList *yList,RatingWiseList *rList)
{
    ifstream myFileStream("IMDB_Manan_Tafheem.csv");
    if (!(myFileStream.is_open()))
    {
        cout << "Failed to open file  " << endl;
    }

    string line;
    string tempstring = "";
    string temp2string = "";
    int i = 0;
    int year = 0;
    getline(myFileStream, line);
    while (getline(myFileStream, line))
    {
        MovieNode *mNode = new MovieNode();
        stringstream ss(line);

        getline(ss, mNode->data.movie_title, ',');

        // Fetching genre - starts
        string genre, temp;
        getline(ss, temp, ',');
        int j = 0;
        do
        {
            if (temp[j] == '|')
            {
                mNode->data.genre.push_back(genre);
                AddGenre(gList,mNode, genre);
                genre = "";
                j++;
            }
            genre += temp[j];
            j++;
        } while(temp[j]!='\0');
        mNode->data.genre.push_back(genre);
        AddGenre(gList,mNode,genre);
        // Fetching genre - ends


        // Fetching title_year and converting into integer - starts
        getline(ss, tempstring, ',');
        int index;
        if (tempstring.empty() || tempstring == "0"){
            year = 0;
            index = 101;
        }
        else{
            year = stoi(tempstring);
            index = year - yList->year_min;
        }
        mNode->data.title_year = year;
        YearWiseListNode *movie_toinsert = new YearWiseListNode();
        movie_toinsert->pdata = mNode;
        movie_toinsert->next = NULL;
        if(yList->pstart_YearWise[index] == NULL)
            yList->pstart_YearWise[index] = movie_toinsert;
        else{
            YearWiseListNode *temp_ploc=yList->pstart_YearWise[index];
            while (temp_ploc->next != NULL)
            {
                temp_ploc = temp_ploc->next;
            }
            temp_ploc->next = movie_toinsert;
        }
        // ends


        // Fetching imdb_score and converting into float - stars
        getline(ss, tempstring, ',');
        float rating;
        if (tempstring.empty()){
            rating = 0.0;
            //r_index = rList->max_index;
        }
        else{
            rating = stod(tempstring);
        }
        mNode->data.imdb_score = rating;
        rList->InsertNodeRatingWise(rating);
        rList->SearchRatingWiseForRepetition(rating);
        RatingMovieNode *temp_rating_movie = new RatingMovieNode();
        temp_rating_movie->pdata = mNode;
        temp_rating_movie->next = NULL;
        if(rList->loc->start_rating_movie==NULL){
            rList->loc->start_rating_movie = temp_rating_movie;
        }
        else{
            RatingMovieNode *ploc = rList->loc->start_rating_movie;
            while(ploc->next!=NULL){
                ploc = ploc->next;
            }
            ploc->next = temp_rating_movie;
        }
        // ends


        //Fetching director name and storing it in directors list and pointing that to movie list
        getline(ss, tempstring, ','); // director name
        getline(ss, temp2string, ','); // facebook likes
        if (!tempstring.empty()){
            MoviesDirected *directedmovie = new MoviesDirected();
            directedmovie->pdata = mNode;
            directedmovie->next = NULL;
            if (!dList->SearchForRepetition(tempstring))
            {
                DirectorNode *dNode = new DirectorNode();
                dNode->data.director_name = tempstring;
                // Fetching director_fb_likes and converting into integer
                if (temp2string.empty())
                    dNode->data.director_facebook_likes = -1;
                else
                    dNode->data.director_facebook_likes = stoi(temp2string);
                mNode->data.pdirector = dNode; // pointing movie node's director node to director node.
                dNode->start = directedmovie;
                if (dList->IsDirectorListEmpty())
                {
                    dList->start = dNode;
                    dList->last = dNode;
                }
                else
                {
                    dList->last->next = dNode;
                    dList->last = dNode;
                }
            }
            else
            {
                mNode->data.pdirector = dList->loc;
                MoviesDirected *ploc = new MoviesDirected();
                ploc = dList->loc->start;
                while (ploc->next != NULL)
                {
                    ploc = ploc->next;
                }
                ploc->next = directedmovie;
            }
        }
        // ends


        // Fetching num_critics and converting into integer
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            mNode->data.num_critic_for_reviews = 0;
        else
            mNode->data.num_critic_for_reviews = stoi(tempstring);
        // ends


        // Fetching duration and converting into integer
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            mNode->data.duration = 0;
        else
            mNode->data.duration = stoi(tempstring);
        // ends

        // Fetching actors, storing them in array list and doing required pointing.
        for (int i = 0; i < 3; ++i)
        {
            getline(ss, tempstring, ',');  // actor name
            getline(ss, temp2string, ','); // facebook likes
            if (tempstring.empty())
                continue; // if no actor move to next loop

            // Runs if actor does not exist in list.
            if (!aList->SearchForRepetition(tempstring))
            {
                // Creating an actor node and assiging it data.
                ActorNode *aNode = new ActorNode();
                aNode->data.actor_name = tempstring;
                if (temp2string.empty())
                    aNode->data.actor_facebook_likes = 0;
                else
                    aNode->data.actor_facebook_likes = stoi(temp2string);

                // If a new actor is created, it will be its first movie.
                // Movie added to actor's MovieActedIn list
                MoviesActedIn *movie_to_insert = new MoviesActedIn();
                movie_to_insert->pdata = mNode;
                movie_to_insert->next = NULL;
                aNode->start = movie_to_insert;
                // new node created in Movie's ActorsInMovie list and actor is added.
                ActorsInMovie *actor_to_insert = new ActorsInMovie();
                actor_to_insert->pdata = aNode;
                actor_to_insert->next = NULL;
                // If Movie's ActorInMovie list is empty, add actor to first node
                if (mNode->data.pstart_actor == NULL)
                {
                    mNode->data.pstart_actor = actor_to_insert;
                }
                    // Otherwise add it to the last.
                else
                {
                    ActorsInMovie *ploc = new ActorsInMovie();
                    ploc = mNode->data.pstart_actor;
                    while (ploc->next != NULL)
                    {
                        ploc = ploc->next;
                    }
                    ploc->next = actor_to_insert;
                }

                // Finally add created actor node to Actor List.
                if (aList->isEmpty())
                {
                    aList->start = aNode;
                    aList->last = aNode;
                }
                else
                {
                    aList->last->next = aNode;
                    aList->last = aNode;
                }
            }

                // If actor already exists.
            else
            {
                // Add Movie to the last of actor's MoviesActedIn list.
                MoviesActedIn *movie_to_insert = new MoviesActedIn;
                MoviesActedIn *ploc = new MoviesActedIn;
                movie_to_insert->pdata = mNode;
                movie_to_insert->next = NULL;
                ploc = aList->loc->start;
                while (ploc->next != NULL)
                {
                    ploc = ploc->next;
                }
                ploc->next = movie_to_insert;


                // Create a node in ActorsInMovie list which points to the found actor.
                ActorsInMovie *actor_to_insert = new ActorsInMovie();
                actor_to_insert->pdata = aList->loc;
                actor_to_insert->next = NULL;

                // If this actor is the first actor of ActorsInMovie list for this movie
                if (mNode->data.pstart_actor == NULL)
                {
                    mNode->data.pstart_actor = actor_to_insert;
                }

                    // Otherwise add this to the end of ActorsInMovie list for this movie.
                else
                {
                    ActorsInMovie *ploc = new ActorsInMovie();
                    ploc = mNode->data.pstart_actor;
                    while (ploc->next != NULL)
                    {
                        ploc = ploc->next;
                    }
                    ploc->next = actor_to_insert;
                }

                // Reintializing strings for next loop.
                temp2string = "";
                tempstring = "";
            }
        }


        // Fetching gross and converting into float
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            mNode->data.gross = 0;
        else
            mNode->data.gross = stoll(tempstring);
        // ends


        // Fetching num_voted_users and converting into integer
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            mNode->data.num_voted_users = 0;
        else
            mNode->data.num_voted_users = stoi(tempstring);
        // ends


        // Fetching cast_total and converting in to integer
        getline(ss, tempstring, ',');

        if (tempstring.empty())
            mNode->data.cast_total = 0;
        else
            mNode->data.cast_total = stoi(tempstring);
        // ends


        // Fetching facenumber_in_poster and converting in to the integer
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            mNode->data.facenumber_in_poster = 0;
        else
            mNode->data.facenumber_in_poster = stoi(tempstring);
        // ends

        // Fetching keyword and storing them in plot_keyword vector
        tempstring ="";
        string keyword;
        getline(ss, tempstring, ',');
        int x = 0;
        do
        {
            if (tempstring[x] == '|')
            {
                mNode->data.plot_keywords.push_back(keyword);
                keyword = "";
                x++;
            }
            keyword += tempstring[x];
            x++;
        } while (tempstring[x] != '\0');
        mNode->data.plot_keywords.push_back(keyword);
        // ends


        // Fetching imdb_link
        getline(ss, mNode->data.movie_imdb_link, ',');

        // Fetching numuser and converting in to integer
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            mNode->data.num_user_for_reviews = 0;
        else
            mNode->data.num_user_for_reviews = stoi(tempstring);
        // ends

        // Fetching langauge
        getline(ss, mNode->data.language, ',');

        // Fetching country
        getline(ss, mNode->data.country, ',');
        ;

        // Fetching content_rating
        getline(ss, mNode->data.content_rating, ',');


        // Fetching budget and converting in to integer
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            mNode->data.budget = 0;
        else
            mNode->data.budget = stoll(tempstring);
        // ends

        // Fetching aspect_ratio and converting into float
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            mNode->data.aspect_ratio = 0;
        else
            mNode->data.aspect_ratio = stof(tempstring);
        // ends

        // Fetching movie_facebook_likes and converting in to integer
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            mNode->data.movie_facebook_likes = 0;
        else
            mNode->data.movie_facebook_likes = stoi(tempstring);
        // ends

        // Fetching color
        getline(ss, mNode->data.color, ',');

        // Adding Movie Node to MovieList.
        if (mList->IsMovieListEmpty())
        {
            mList->start = mNode;
            mList->last = mNode;
        }
        else
        {
            mList->last->next = mNode;
            mList->last = mNode;
        }
        i++;
    }
}

// Add genre is used by parser to add genre type to genre list.
void AddGenre(GenreList *gList, MovieNode *mNode, string genre){
    GenreMovieNode *pgenre_movie_insert = new GenreMovieNode();
    pgenre_movie_insert->pdata = mNode;
    pgenre_movie_insert->next = NULL;
    if(!gList->SearchGenreForReptition(genre)){
        GenreListNode *pgenre_node_toinsert = new GenreListNode();
        pgenre_node_toinsert->genre_type = genre;
        pgenre_node_toinsert->start_genre_movie = pgenre_movie_insert;
        if (gList->IsGenreEmpty())
        {
            gList->start = pgenre_node_toinsert;
            gList->last = pgenre_node_toinsert;
        }
        else
        {
            gList->last->next = pgenre_node_toinsert;
            gList->last = pgenre_node_toinsert;
        }
    }
    else{
        GenreMovieNode *ploc = new GenreMovieNode();
        ploc = gList->loc->start_genre_movie;
        while(ploc->next!=NULL){
            ploc = ploc->next;
        }
        ploc->next = pgenre_movie_insert;
    }
}

// prompts
void MainScreen(){
    cout<<"1. Search actor and print his\\her movies in chronological order."<<endl;
    cout<<"2. Search coactors for given actor."<<endl;
    cout<<"3. Search coactors of a given actor and print them once."<<endl;
    cout<<"4. Print coactors of coactors"<<endl;
    cout<<"5. Check if the given actors are coactors or not"<<endl;
    cout<<"6. Print all movies of a director"<<endl;
    cout<<"7. Print all directors of given genre."<<endl;
    cout<<"8. Search movie"<<endl;
    cout<<"9. Print movies in a given year"<<endl;
    cout<<"10. Print movies in year wise order"<<endl;
    cout<<"11. Print movies of given genre in rating wise"<<endl;
    cout<<"12. Print movies rating wise"<<endl;
    cout<<"Press any other key to Exit"<<endl;
}


// Searches for the given actor and print all of his/her movies in chronoligcal order
void Function1SearchAndPrintActor(ActorList *aList,YearWiseList *yList, string name) {
    if (!aList->SearchForRepetition(name)){
        cout<<"Actor not found."<<endl;
    }else{
        YearWiseListNode *temp_year_node;
        ActorsInMovie *temp_actor;
        short unsigned int count = 0;
        for(int i=0; i<yList->max_index;i++){
            temp_year_node = yList->pstart_YearWise[i];
            while(temp_year_node!=NULL){
                temp_actor = temp_year_node->pdata->data.pstart_actor;
                while(temp_actor!=NULL){
                    if(temp_actor->pdata->data.actor_name == name){
                        cout<<temp_year_node->pdata->data.title_year<<" ";
                        cout<<temp_year_node->pdata->data.movie_title.substr(0,temp_year_node->pdata->data.movie_title.size()-2);
                        cout<<endl;
                        count++;
                    }
                    temp_actor = temp_actor->next;
                }
                temp_year_node = temp_year_node->next;
            }
        }
        cout<<"\n Total movies acted in: "<<count<<endl;
    }
}

// Searches for coactors of given actor along with movie names they have worked in
void Function2SearchCoActors(ActorList *aList, string actor_name) {

    if (!aList->SearchForRepetition(actor_name)) {
        cout << "Actor not Found. Try Again!";
    } else {
        ActorNode *actor = aList->loc;
        MoviesActedIn *temp_movie_acted_in = actor->start;
        while (temp_movie_acted_in != NULL) {
            ActorsInMovie *temp_actor_in_movie = temp_movie_acted_in->pdata->data.pstart_actor;
            string movie_title = temp_movie_acted_in->pdata->data.movie_title.substr(0,
                                                                                     (temp_movie_acted_in->pdata->data.movie_title.length()) -
                                                                                     2);
            cout << "\n" << movie_title << endl;
            while (temp_actor_in_movie != NULL) {
                if (temp_actor_in_movie->pdata->data.actor_name != actor_name)
                    cout << temp_actor_in_movie->pdata->data.actor_name << ", ";
                temp_actor_in_movie = temp_actor_in_movie->next;
            }
            cout << endl;
            temp_movie_acted_in = temp_movie_acted_in->next;
        }
    }
}

// Searches coactors of given actor, stores them and then print such that no actor repeats
void Function3UniqueCoActors(ActorList *aList,MovieList *mList,string actor_name) {
    if (!aList->SearchForRepetition(actor_name)) {
        cout << "Actor not Found. Try Again!";
    } else{
        set<string> co_actors{};
        ActorNode *actor=aList->loc;
        MoviesActedIn *temp_movie_acted_in=actor->start;
        while (temp_movie_acted_in != NULL) {
            ActorsInMovie *temp_actor_in_movie = temp_movie_acted_in->pdata->data.pstart_actor;
            while (temp_actor_in_movie != NULL) {
                if (temp_actor_in_movie->pdata->data.actor_name != actor_name)
                    co_actors.insert(temp_actor_in_movie->pdata->data.actor_name);
                temp_actor_in_movie = temp_actor_in_movie->next;
            }
            temp_movie_acted_in = temp_movie_acted_in->next;
        }
        for (auto i = co_actors.begin(); i != co_actors.end(); ++i) {
            cout<<*i<<" in movie: "<<endl;
            Function5CheckIfCoActorsOrNot(aList,mList,actor_name,*i);
            cout<<endl;
        }
    }
}

// Search coactors of coactors and print them
void Function4PrintCoActorsOfCoActors(ActorList *aList, string actor_name) {
    if (!aList->SearchForRepetition(actor_name)) {
        cout << "Actor not found." << endl;
    } else {
        MoviesActedIn *temp_movie_a = aList->loc->start;
        set<string> coactors_of_coactors{};
        while (temp_movie_a != NULL) {
            ActorsInMovie *temp_actor_bc = temp_movie_a->pdata->data.pstart_actor;
            while (temp_actor_bc != NULL) {
                if (temp_actor_bc->pdata->data.actor_name != actor_name) {
                    MoviesActedIn *temp_movie_bc = temp_actor_bc->pdata->start;
                    while (temp_movie_bc != NULL) {
                        ActorsInMovie *temp_actor_de = temp_movie_bc->pdata->data.pstart_actor;
                        while (temp_actor_de != NULL) {
                            if (temp_actor_de->pdata->data.actor_name != actor_name &&
                                temp_actor_de->pdata->data.actor_name != temp_actor_bc->pdata->data.actor_name) {
                                coactors_of_coactors.insert(temp_actor_de->pdata->data.actor_name);
                            }
                            temp_actor_de = temp_actor_de->next;
                        }
                        temp_movie_bc = temp_movie_bc->next;
                    }

                }
                temp_actor_bc = temp_actor_bc->next;
            }
            temp_movie_a = temp_movie_a->next;
        }

        set<string>::iterator it = coactors_of_coactors.begin();
        while (it != coactors_of_coactors.end()) {
            cout << *it << endl;
            it++;
        }
    }
}

// Checks if given actors have worked together
void Function5CheckIfCoActorsOrNot(ActorList *aList, MovieList *mList, string actor_a, string actor_b) {
    if (!(aList->SearchForRepetition(actor_a) && aList->SearchForRepetition(actor_b))) {
        cout << "One or both of the actors not Found. Try Again!";
    } else {
        short int count = 0;
        bool actor_a_found = false;
        bool actor_b_found = false;
        MovieNode *temp_movie = mList->start;
        ActorsInMovie *temp_actor;
        while (temp_movie != NULL) {
            temp_actor = temp_movie->data.pstart_actor;
            while (temp_actor != NULL) {
                if (temp_actor->pdata->data.actor_name == actor_a) {
                    actor_a_found = true;
                }
                if (temp_actor->pdata->data.actor_name == actor_b) {
                    actor_b_found = true;
                }
                temp_actor = temp_actor->next;
            }
            if (actor_a_found && actor_b_found) {
                cout << temp_movie->data.movie_title.substr(0, temp_movie->data.movie_title.length() - 2) << endl;
                count++;
            }
            actor_a_found = false;
            actor_b_found = false;

            temp_movie = temp_movie->next;
        }
        if (count == 0) {
            cout << "They're not Co-Actors of Each Other in Any Movie.";
        }
    }
}

// Print all movies of a given director
void Function6PrintAllMoviesOfDirector(DirectorList *dList, string name) {
    if (!dList->SearchForRepetition(name)) {
        cout << "Director not found." << endl;
    } else {
        DirectorNode *temp_director = dList->loc;
        MoviesDirected *temp_movies_directed = temp_director->start;
        cout << "The movies directed by " << temp_director->data.director_name << " are:" << endl;
        while (temp_movies_directed != NULL) {
            cout << temp_movies_directed->pdata->data.movie_title.substr(0,
                                                                         temp_movies_directed->pdata->data.movie_title.length() -
                                                                         2) << endl;
            temp_movies_directed = temp_movies_directed->next;
        }
    }
}

// Print director names of all movies of given genre
void Function7PrintMoviesOfDirectorOfCertainGenre(GenreList *gList, string genre) {
    if (!gList->SearchGenreForReptition(genre)) {
        cout << "No Such Genre";
    } else {
        set<string> director_list;
        GenreMovieNode *temp_genre_movie = gList->loc->start_genre_movie;
        while (temp_genre_movie != NULL) {
            string temp = temp_genre_movie->pdata->data.pdirector->data.director_name;
            director_list.insert(temp);
            temp_genre_movie = temp_genre_movie->next;
        }
        // Creating a iterator pointing to start of set
        set<string>::iterator it = director_list.begin();
        while (it != director_list.end()) {
            // Print the element
            cout << (*it) << endl;
            //Increment the iterator
            it++;
        }
    }
}

// Prints details of given movie
void Function8SearchAndPrintMovie(MovieList *mList, string movie_name) {
    if (!mList->Search(movie_name)) {
        cout << "Movie Not Found";
    } else {
        MovieNode *temp_movie = mList->loc;
        cout << "Movie Name: " << movie_name << endl;
        cout << "Release Year: " << temp_movie->data.title_year << endl;
        cout << "Directed By: " << temp_movie->data.pdirector->data.director_name << endl;
        cout << "Star Role: " << temp_movie->data.pstart_actor->pdata->data.actor_name << endl;
        cout << "IMDB Rating: " << temp_movie->data.imdb_score << endl;
        cout << "Gross: " << temp_movie->data.gross << endl;
        cout << "Language: " << temp_movie->data.language << endl;
        cout << "Genre: " << temp_movie->data.genre[0] << endl;

    }
}

// Prints all movies in a given year.
void Function9PrintMoviesInGivenYear(YearWiseList *yList, int year){
    if(year<1916 || year>2016) // min and max years in database
    {
        cout<<"The record is only from 1916 to 2016"<<endl;
    }
    else{
        if(yList->pstart_YearWise[year-yList->year_min] == NULL){
            cout<<"No Movies found in given Year"<<endl;
        }
        else{
            YearWiseListNode *temp_movie_node = new YearWiseListNode();
            temp_movie_node = yList->pstart_YearWise[year-yList->year_min];
            while(temp_movie_node!=NULL){
                cout<<temp_movie_node->pdata->data.movie_title.substr(0,temp_movie_node->pdata->data.movie_title.length()-2)<<endl;
                temp_movie_node = temp_movie_node->next;
            }
        }
    }

}

// Print movies in year wise order (ascending)
void Function10PrintMoviesYearWise(YearWiseList *yList){
    int size = yList->max_index;
    for(int i=0; i < size; i++)
    {
        YearWiseListNode *temp_yearwise_movie = yList->pstart_YearWise[i];
        if(i==size-1){
            cout<<"Following Movies do not have years in database."<<endl;
        }
        else
            cout<<"\nYEAR "<<i+yList->year_min<<endl;
        while(temp_yearwise_movie!=NULL){
            cout<<temp_yearwise_movie->pdata->data.movie_title.substr(0,temp_yearwise_movie->pdata->data.movie_title.length()-2)<<"  ";
            cout<<temp_yearwise_movie->pdata->data.title_year<<endl;
            temp_yearwise_movie = temp_yearwise_movie->next;
        }
    }
}

// Print movies of given genre in rating wise (ascending) order.
void Function11And13PrintMoviesOfGivenGenreRatingWise(RatingWiseList *rList, string Genre){
    RatingWiseListNode *temp_ratingwise_node = rList->start;
    int count = 1;
    while(temp_ratingwise_node!=NULL){
        RatingMovieNode *temp_ratingwise_movie = temp_ratingwise_node->start_rating_movie;
        while(temp_ratingwise_movie!=NULL){
            for(auto i=temp_ratingwise_movie->pdata->data.genre.begin(); i!=temp_ratingwise_movie->pdata->data.genre.end(); i++){
                if(*i == Genre){
                    cout<<count<<" "<<temp_ratingwise_movie->pdata->data.movie_title.substr(0,temp_ratingwise_movie->pdata->data.movie_title.length()-2)<<"  ";
                    cout<<temp_ratingwise_movie->pdata->data.imdb_score<<endl;
                    count++;
                }
            }

            temp_ratingwise_movie = temp_ratingwise_movie->next;
        }
        temp_ratingwise_node =temp_ratingwise_node->next;
    }
}

// Print all movies in rating wise (ascending) order
void Function12PrintMoviesRatingWise(RatingWiseList *rList){
    RatingWiseListNode *temp_ratingwise_node = rList->start;
    int i=1;
    while(temp_ratingwise_node!=NULL){
        RatingMovieNode *temp_ratingwise_movie = temp_ratingwise_node->start_rating_movie;
        while(temp_ratingwise_movie!=NULL){
            cout<<i<<" ";
            cout<<temp_ratingwise_movie->pdata->data.movie_title.substr(0,temp_ratingwise_movie->pdata->data.movie_title.length()-2)<<"  ";
            cout<<temp_ratingwise_movie->pdata->data.imdb_score<<endl;
            temp_ratingwise_movie = temp_ratingwise_movie->next;
            i++;
        }
        temp_ratingwise_node =temp_ratingwise_node->next;
    }
}








int main()
{
    MovieList *mList = new MovieList();
    ActorList *aList = new ActorList();
    DirectorList *dList = new DirectorList();
    GenreList *gList = new GenreList();
    YearWiseList *yList = new YearWiseList();
    RatingWiseList *rList = new RatingWiseList();
    parser(mList, aList, dList, gList, yList, rList);

    cout<<"\t DSA MINI PROJECT"<<endl;
    cout<<"Team Members: Abdul Manan | 303323 \t Tafheem Ul Islam | 321906"<<endl;
    cout<<"The Projects is based on IMDB 5000 Movies. Select one of the following operations for demo"<<endl;
    short int loop = 0;
    short int input = 0;
    string input_string_1 ="";
    string input_string_2 ="";
    short unsigned int input_year = 0;
    do{
        MainScreen();
        cout<<"Please select the operation: ";
        cin>>input;
        cout<<endl<<endl;
        switch (input)
        {
            case 1:
                cout<<"Enter actor name: ";
                cin.ignore();
                getline(cin,input_string_1);
                Function1SearchAndPrintActor(aList,yList,input_string_1);
                break;
            case 2:
                cout<<"Enter actor name: ";
                cin.ignore();
                getline(cin,input_string_1);
                Function2SearchCoActors(aList,input_string_1);
                break;
            case 3:
                cout<<"Enter actor name: ";
                cin.ignore();
                getline(cin,input_string_1);
                Function3UniqueCoActors(aList,mList,input_string_1);
                break;
            case 4:
                cout<<"Enter actor name: ";
                cin.ignore();
                getline(cin,input_string_1);
                Function4PrintCoActorsOfCoActors(aList,input_string_1);
                break;
            case 5:
                cout<<"Enter actor 01 name: ";
                cin.ignore();
                getline(cin,input_string_1);
                cout<<"Enter actor 02 name: ";
                getline(cin,input_string_2);
                Function5CheckIfCoActorsOrNot(aList,mList,input_string_1,input_string_2);
                break;
            case 6:
                cout<<"Enter director name: ";
                cin.ignore();
                getline(cin,input_string_1);
                Function6PrintAllMoviesOfDirector(dList,input_string_1);
                break;
            case 7:
                cout<<"Enter Genre: ";
                cin.ignore();
                getline(cin,input_string_1);
                Function7PrintMoviesOfDirectorOfCertainGenre(gList,input_string_1);
                break;
            case 8:
                cout<<"Enter movie name in full (case sensitive): ";
                cin.ignore();
                getline(cin,input_string_1);
                Function8SearchAndPrintMovie(mList,input_string_1);
                break;
            case 9:
                cout<<"Enter Year (1996-2016): ";
                cin>>input_year;
                Function9PrintMoviesInGivenYear(yList, input_year);
                break;
            case 10:
                Function10PrintMoviesYearWise(yList);
                break;
            case 11:
                cout<<"Enter genre:";
                cin.ignore();
                getline(cin,input_string_1);
                Function11And13PrintMoviesOfGivenGenreRatingWise(rList,input_string_1);
                break;
            case 12:
                Function12PrintMoviesRatingWise(rList);
                break;
            default:
                exit(0);
                break;
        }
        cout<<endl;
        cout<<"Do you want to continue? Press any key to continue or (-1) to exit"<<endl;
        cin>>input;
        cout<<endl<<endl<<endl;
    }while(input!=-1);
    return 0;
}
