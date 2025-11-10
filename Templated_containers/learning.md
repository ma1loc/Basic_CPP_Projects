Q&A about CPP08

what is templated containers and diffrence between normall template?
what is the containers in cpp?
what is iterators and diffrence between them and pointer?
what is algorithms in cpp and used for (is that <algorithm>)?
what is std::array and diff between normal array?

AI Questions
Templates

What are function templates and how do you declare them?
What are class templates and how do they differ from regular classes?
Where should template implementations be placed (header files vs .tpp files)?
Why can't template implementations be in .cpp files like regular functions?

STL Containers

What are the main STL containers (vector, list, map, stack, etc.)?
What are the differences between sequence containers and associative containers?
How do you choose which container to use for a specific task?
What operations are common to all containers?
What does "store a maximum of N elements" mean in terms of container design?

Iterators

What are iterators and why are they important?
What are the different types of iterators (input, output, forward, bidirectional, random access)?
How do you use begin() and end() with containers?
How do you iterate through a container using iterators?
What's the difference between iterator and const_iterator?
Why is std::stack not iterable by default?
How can you add iterator support to a custom container?

Algorithms

What algorithms are available in the <algorithm> header?
How do algorithms work with iterators?
How would you find an element in a container using STL algorithms?

Range Operations

What does "range of iterators" mean?
How can you add multiple elements to a container using a range of iterators?
What container member functions accept iterator ranges?

Inheritance and Composition

What does "implemented in terms of" mean (composition/aggregation)?
How can you extend functionality of an existing STL container?
Can you inherit from STL containers? Should you?

Exception Handling

When should you throw exceptions vs return error values?
What exceptions should be thrown when containers are full or empty?
How do standard containers handle error conditions?

Span/Distance Concepts

What does "span" or "distance" between numbers mean?
How would you efficiently find minimum/maximum differences in a collection?

If you can answer all these questions confidently, you understand the Module 08 concepts completely!

what is the dueqe?
why the std::string is contianer too?

>>>>>>>>>>>>>>>>>>>>>>>>>>> Answers TO the Q&A >>>>>>>>>>>>>>>>>>>>>

Continer interface is the methodes that continer provide like push_back in vector
    is an interface part in vector container.

What is STL:
    tha standered template librarys 

>>> The containers of STL
Sequence Container:
    std::vector -> like the array but can be re-sizeable in runtime and safe then arry
        and it
        >>> vector interfaces
            .at()
            .push_back()
            .front()
            .back()
            .....
    std::deque
    std::list
    std::array (not in cpp98)
    std::forward_list (not in cpp98) is just linked list

Ordered assositave Container:
    std::map
    std::set
    std::multimap
    std::multiset

Ordered assositave Container:
    std::unordered_map (not in cpp98)
    std::unordered_set (not in cpp98)
    std::unordered_multimap (not in cpp98)
    std::unordered_multiset (not in cpp98)