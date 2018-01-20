#ifndef OBJ_MEM_ALLOCATOR_H
#define OBJ_MEM_ALLOCATOR_H
// Serves as template allocator for Wind Objects.

template<class T>
class ObjMemAllocator
{
public:
ObjMemAllocator()
{
}
~ObjMemAllocator()
{
}

T* memory(int amount = 1) const
{
        return new T[amount];
}
};

#endif // OBJ_MEM_ALLOCATOR_H
