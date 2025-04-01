
#include "Movie.h"
#define HASH_START 17
#define RES_MULT 31

/**
 * hash function used for a unordered_map (implemented for you)
 * @param movie shared pointer to movie
 * @return an integer for the hash map
 */
struct MovieComparator {
    bool operator()(const sp_movie& lhs, const sp_movie& rhs) const {
        if (lhs->get_year() == rhs->get_year()) {
            return lhs->get_name() < rhs->get_name();
        }
        return lhs->get_year() < rhs->get_year();
    }
};

std::size_t sp_movie_hash(const sp_movie& movie){
    std::size_t res = HASH_START;
    res = res * RES_MULT + std::hash<std::string>()(movie->get_name());
    res = res * RES_MULT + std::hash<int>()(movie->get_year());
    return res;
}
Movie::Movie(const std::string& name,const int year)
: name_(name),relase_date_(year){}

Movie::~Movie() {}
std::ostream& operator<<(std::ostream &os,const Movie& movie){
    os << movie.get_name() << " ("<< movie.get_year() << ")" << std::endl;
    return os;
}
bool Movie::operator<(const Movie& rhs) const {
    if(relase_date_ == rhs.relase_date_) {
        return name_ < rhs.name_;
    }
    return relase_date_ < rhs.relase_date_;
}
std::string Movie::get_name() const {
    return name_;
}
int Movie::get_year() const {
    return relase_date_;
}

/**
 * equal function used for an unordered_map (implemented for you)
 * @param m1
 * @param m2
 * @return true if the year and name are equal else false
 */
bool sp_movie_equal(const sp_movie& m1,const sp_movie& m2){
    return !(*m1 < *m2) && !(*m2 < *m1);
}





