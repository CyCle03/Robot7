#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

using namespace std;

struct LottoResult
{
    vector<int> numbers;
    int bonus;
};

class ILottoNumberGenerator
{
public:
    virtual LottoResult generate() = 0;
    virtual ~ILottoNumberGenerator() {}
};

class RamdomLottoNumberGenerator : public ILottoNumberGenerator
{
private:
    mt19937 gen;

public:
    RamdomLottoNumberGenerator() : gen(random_device{}()) {}

    LottoResult generate() override
    {
        vector<int> pool(45);
        iota(pool.begin(), pool.end(), 1);//1~45 숫자 채우기

        //섞기
        shuffle(pool.begin(), pool.end(), gen);//숫자 섞기

        //정렬 전 보너스 번호 추출
        LottoResult result;
        result.numbers.assign(pool.begin(), pool.begin() + 6);
        result.bonus = pool[6];//7개 숫자 중 마지막이 보너스

        //정렬
        sort(result.numbers.begin(), result.numbers.end());

        return result;
    }
};

class ILottoPrinter
{
public:
    virtual ~ILottoPrinter() = default;
    virtual void print(const LottoResult& result) = 0;
};

class ConsolLottoPrinter : public ILottoPrinter
{
public:
    void print(const LottoResult& result) override
    {
        cout << "Lotto Numbers: ";
        for (int num : result.numbers)
        {
            cout << num << " ";
        }
        cout << endl << "Bonus Number: " << result.bonus << endl;
    }
};

class LottoGame
{
private:
    unique_ptr<ILottoNumberGenerator> generator;
    unique_ptr<ILottoPrinter> printer;
public:
    LottoGame(unique_ptr<ILottoNumberGenerator> gen, unique_ptr<ILottoPrinter> prn)
        : generator(move(gen)), printer(move(prn)) {}
    
    void run()
    {
        LottoResult result = generator->generate();
        printer->print(result);
    }
};

int main()
{
    auto generator = make_unique<RamdomLottoNumberGenerator>();
    auto printer = make_unique<ConsolLottoPrinter>();

    LottoGame game(move(generator), move(printer));
    game.run();

    return 0;
}
