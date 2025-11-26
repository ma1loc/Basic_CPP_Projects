# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

typedef std::map<unsigned int, double>::iterator iter;

class BitcoinExchange
{
    private:
        std::map<unsigned int, double> DB;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();

        void set_DB();
        void set_FInput(std::string input_file);
        void extract_FIpnut_info(std::string &line);
        void get_Bitcoin_rate(unsigned int date, double value);
};

unsigned int    get_date(std::string &line);
float           get_exchange_rate(std::string &line);
bool            is_valid_info_provided(std::string &date, std::string &value);
std::string     get_IDate(std::string &date);
std::string     get_IValue(std::string &value);
int             is_date_valid(std::string &date);
double          is_value_valid(std::string value);
unsigned int    get_days_of_month(int year, int month);
void            show_result(unsigned int date, double value, iter obj);

# endif
