template <typename T>
void print(vector<T> items)
{
    for (auto item : items)
    {
        std::cout << item << " ";
    }
    std::cout << "\n";
}