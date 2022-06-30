#include <iostream>
#include <vector>
#include <random>

class prison_sim_t
{
public:
    prison_sim_t(int num) : num_pris(num), boxes(num), gen(rd()), distrib(0, num-1)
    {
        for (int i = 0; i < num_pris; ++i)
        {
            boxes.at(i) = get_rand_box();
        }
    }

    bool prisoner_success()
    {
        for (int prisoner_num = 0; prisoner_num < num_pris; ++prisoner_num)
        {
            bool good = false;
            int box_no = get_rand_box();

            for (int i = 0; i < (num_pris / 2); ++i)
            {
                //std::cout << box_no << std::endl;
                int value = boxes.at(box_no);
                if (value == prisoner_num) {
                    good = true;
                    break;
                } else {
                    box_no = value;
                }
            }
            if (!good) {
                return false;
            }
        }
        return true;
    }

    int get_rand_box()
    {
        return distrib(gen);
    }

private:
    const int num_pris;
    std::vector<int> boxes;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> distrib;
};

int main()
{

    const int num_rounds = 100;
    int num_success = 0;
    for (int i = 0; i < num_rounds; ++i)
    {
        prison_sim_t prison(100);
        if (prison.prisoner_success())
        {
            ++num_success;
        }
    }

    std::cout << "Number attempts: " << num_rounds << std::endl;
    std::cout << "Success ratio: " << (double)num_success / num_rounds << std::endl;

    return 0;
}
