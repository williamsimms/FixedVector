#define CATCH_CONFIG_MAIN

#include "../vector.hh"

#include "../utility/Vector3.hpp"
#include "../vendor/catch.hpp"

TEST_CASE("Returns the current size of the vector.", "[Size]") {
  SECTION(
      "Returns 0 when the list, is initialized using the Default "
      "Constructor.") {
    Vector<int, 10> vector;
    REQUIRE(vector.Size() == 0);
  }

  SECTION(
      "Returns the size of the list after being initialized with a initializer "
      "list.") {
    Vector<int, 10> vector{1, 2, 3, 4, 5};
    REQUIRE(vector.Size() == 5);
  }

  SECTION(
      "Returns the size of the list after having elements appended to it.") {
    Vector<int, 10> vector{1, 2, 3, 4, 5};
    REQUIRE(vector.Size() == 5);

    vector.PushBack(5);
    REQUIRE(vector.Size() == 6);

    vector.PushBack(12);
    REQUIRE(vector.Size() == 7);

    vector.PushBack(13);
    REQUIRE(vector.Size() == 8);
  }

  SECTION(
      "Returns the size of the list after having elements removed from it.") {
    Vector<int, 10> vector{1, 2, 3, 4, 5};
    REQUIRE(vector.Size() == 5);

    vector.PopBack();
    REQUIRE(vector.Size() == 4);

    vector.PopBack();
    REQUIRE(vector.Size() == 3);
  }

  SECTION(
      "Returns the size of the list after having elements added and removed "
      "from it.") {
    Vector<int, 10> vector{1, 2, 3, 4, 5};
    REQUIRE(vector.Size() == 5);

    vector.PushBack(5);
    REQUIRE(vector.Size() == 6);

    vector.PushBack(12);
    REQUIRE(vector.Size() == 7);

    vector.PushBack(13);
    REQUIRE(vector.Size() == 8);

    vector.PopBack();
    REQUIRE(vector.Size() == 7);

    vector.PopBack();
    REQUIRE(vector.Size() == 6);
  }
}

TEST_CASE("Returns true if the vector is empty, otherwise returns true.",
          "[Empty]") {
  SECTION("Returns true if the list is empty.") {
    Vector<int, 10> vector;
    bool isEmpty = vector.Empty();
    REQUIRE(isEmpty == true);
  }

  SECTION("Returns false if the list is not empty.") {
    Vector<int, 10> vector{1, 2, 3};
    bool isEmpty = vector.Empty();
    REQUIRE(isEmpty == false);
  }
}

TEST_CASE("Returns a reference to the first element in the array.", "[Front]") {
  SECTION("Returns a reference to the first element in the array.") {
    Vector<int, 10> vector{1, 2, 3, 4, 5};
    REQUIRE(vector.Front() == 1);
  }

  SECTION("The value of the element can be changed.") {
    Vector<int, 10> vector{1, 2, 3, 4, 5};
    vector.Front() = 12;
    REQUIRE(vector.Front() == 12);
  }

  SECTION(
      "Returns a reference to the first element in the array when using a "
      "const Vector.") {
    const Vector<int, 10> vector{1, 2, 3, 4, 5};
    REQUIRE(vector.Front() == 1);
  }
}

TEST_CASE("Returns a reference to the last element in the array.", "[Back]") {
  SECTION("Returns a reference to the last element in the array.") {
    Vector<int, 10> vector{1, 2, 3, 4, 5};
    REQUIRE(vector.Back() == 5);
  }

  SECTION("The value of the element can be changed.") {
    Vector<int, 10> vector{1, 2, 3, 4, 5};
    vector.Back() = 12;
    REQUIRE(vector.Back() == 12);
  }

  SECTION(
      "Returns a reference to the last element in the array when using a "
      "const Vector.") {
    const Vector<int, 10> vector{1, 2, 3, 4, 5};
    REQUIRE(vector.Back() == 5);
  }
}

TEST_CASE("Appends a new element to the end of the Vector.", "[PushBack]") {
  SECTION("Pushes a New element to the end of the array using a l-value.") {
    Vector<int, 10> vector;
    REQUIRE(vector.Size() == 0);
    REQUIRE(vector.Capacity() == 10);

    int x = 5;
    vector.PushBack(x);
    REQUIRE(vector[0] == 5);
    REQUIRE(vector.Size() == 1);
    REQUIRE(vector.Capacity() == 10);

    int z = 12;
    vector.PushBack(z);
    REQUIRE(vector[0] == 5);
    REQUIRE(vector[1] == 12);
    REQUIRE(vector.Size() == 2);
    REQUIRE(vector.Capacity() == 10);
  }

  SECTION("Pushes a New element to the end of the array using a r-value.") {
    Vector<int, 10> vector;
    REQUIRE(vector.Size() == 0);
    REQUIRE(vector.Capacity() == 10);

    vector.PushBack(5);
    REQUIRE(vector[0] == 5);
    REQUIRE(vector.Size() == 1);
    REQUIRE(vector.Capacity() == 10);

    vector.PushBack(12);
    REQUIRE(vector[0] == 5);
    REQUIRE(vector[1] == 12);
    REQUIRE(vector.Size() == 2);
    REQUIRE(vector.Capacity() == 10);
  }
}

TEST_CASE("Removes the last element from the Vector.", "[PopBack]") {
  Vector<int, 10> vector{1, 2, 3, 4};

  REQUIRE(vector.Size() == 4);
  REQUIRE(vector.Capacity() == 10);

  REQUIRE(vector[0] == 1);
  REQUIRE(vector[1] == 2);
  REQUIRE(vector[2] == 3);
  REQUIRE(vector[3] == 4);

  vector.PopBack();

  REQUIRE(vector.Size() == 3);
  REQUIRE(vector.Capacity() == 10);

  REQUIRE(vector[0] == 1);
  REQUIRE(vector[1] == 2);
  REQUIRE(vector[2] == 3);
}

TEST_CASE("Returns the element at the desired index.", "[At]") {
  SECTION("Returns a reference to the element at the provided index.") {
    Vector<int, 10> vector{1, 2, 3, 4};

    REQUIRE(vector.Size() == 4);
    REQUIRE(vector.Capacity() == 10);

    REQUIRE(vector.At(0) == 1);
    REQUIRE(vector.At(1) == 2);
    REQUIRE(vector.At(2) == 3);
    REQUIRE(vector.At(3) == 4);
  }

  SECTION("Allows for the editing of the Reference via the At function.") {
    Vector<int, 10> vector{1, 2, 3, 4};

    REQUIRE(vector.Size() == 4);
    REQUIRE(vector.Capacity() == 10);

    REQUIRE(vector.At(0) == 1);
    REQUIRE(vector.At(1) == 2);
    REQUIRE(vector.At(2) == 3);
    REQUIRE(vector.At(3) == 4);

    vector.At(0) = 12;
    vector.At(3) = 22;

    REQUIRE(vector.At(0) == 12);
    REQUIRE(vector.At(1) == 2);
    REQUIRE(vector.At(2) == 3);
    REQUIRE(vector.At(3) == 22);
  }

  SECTION(
      "Returns a non modifiable reference to the element at the provided index "
      "when working with a const Vector.") {
    const Vector<int, 10> vector{1, 2, 3, 4};

    REQUIRE(vector.Size() == 4);
    REQUIRE(vector.Capacity() == 10);

    REQUIRE(vector.At(0) == 1);
    REQUIRE(vector.At(1) == 2);
    REQUIRE(vector.At(2) == 3);
    REQUIRE(vector.At(3) == 4);
  }
}

TEST_CASE("Emplaces the new element at the back of the Vector.",
          "[Emplace Back]") {
  Vector<Vector2, 20> vector;

  REQUIRE(vector.Size() == 0);
  REQUIRE(vector.Capacity() == 20);

  Vector2 vector2One(2, 3);

  vector.EmplaceBack(2, 3);

  REQUIRE(vector.Size() == 1);
  REQUIRE(vector.Capacity() == 20);

  REQUIRE(vector.Back() == vector2One);

  Vector2 vector2Two(1, 2);

  vector.EmplaceBack(1, 2);
  REQUIRE(vector.Size() == 2);
  REQUIRE(vector.Capacity() == 20);

  REQUIRE(vector.Back() == vector2Two);
}

TEST_CASE(
    "Returns the index of the first occurence of the provided data in the "
    "Vector. Otherwise returns -1.",
    "[Index Of]") {
  Vector<int, 10> vector{1, 2, 3, 4, 5, 5, 2, 1};

  REQUIRE(vector.IndexOf(1) == 0);
  REQUIRE(vector.IndexOf(2) == 1);
  REQUIRE(vector.IndexOf(3) == 2);
  REQUIRE(vector.IndexOf(4) == 3);
  REQUIRE(vector.IndexOf(5) == 4);
  REQUIRE(vector.IndexOf(12) == -1);
}

TEST_CASE(
    "Returns the index of the last occurence of the provided data in the "
    "Vector. Otherwise returns -1.",
    "[Last Index Of]") {
  Vector<int, 10> vector{1, 2, 3, 4, 5, 5, 2, 1};

  REQUIRE(vector.LastIndexOf(1) == 7);
  REQUIRE(vector.LastIndexOf(2) == 6);
  REQUIRE(vector.LastIndexOf(3) == 2);
  REQUIRE(vector.LastIndexOf(4) == 3);
  REQUIRE(vector.LastIndexOf(5) == 5);
  REQUIRE(vector.LastIndexOf(12) == -1);
}

TEST_CASE(
    "Returns a pointer to the first occurrence of the element with matching "
    "data.",
    "[Find]") {
  SECTION(
      "Returns nullptr if no element in the Vector matches the passed in "
      "data.") {
    Vector<int, 10> vector{1, 2, 3, 4, 5};
    REQUIRE(vector.Find(12) == nullptr);
  }

  SECTION("Returns a pointer to the first element found with matching  data.") {
    Vector<int, 10> vector{1, 2, 3, 4, 5, 1, 2, 3};

    REQUIRE(vector[0] == 1);
    REQUIRE(vector[1] == 2);
    REQUIRE(vector[2] == 3);
    REQUIRE(vector[3] == 4);
    REQUIRE(vector[4] == 5);
    REQUIRE(vector[5] == 1);
    REQUIRE(vector[6] == 2);
    REQUIRE(vector[7] == 3);

    REQUIRE(*(vector.Find(1)) == 1);
    REQUIRE(*(vector.Find(2)) == 2);
    REQUIRE(*(vector.Find(3)) == 3);

    *(vector.Find(1)) += 10;
    *(vector.Find(2)) += 10;
    *(vector.Find(3)) += 10;

    REQUIRE(vector[0] == 11);
    REQUIRE(vector[1] == 12);
    REQUIRE(vector[2] == 13);
    REQUIRE(vector[3] == 4);
    REQUIRE(vector[4] == 5);
    REQUIRE(vector[5] == 1);
    REQUIRE(vector[6] == 2);
    REQUIRE(vector[7] == 3);
  }
}

TEST_CASE("Returns the amount of free capacity the vector has available.",
          "[Free Capacity]") {
  Vector<int, 10> vectorOne{1, 2, 3, 4, 5};

  REQUIRE(vectorOne.Size() == 5);
  REQUIRE(vectorOne.Capacity() == 10);
  REQUIRE(vectorOne.FreeCapacity() == 5);

  vectorOne.PushBack(6);

  REQUIRE(vectorOne.Size() == 6);
  REQUIRE(vectorOne.Capacity() == 10);
  REQUIRE(vectorOne.FreeCapacity() == 4);

  vectorOne.PushBack(11);

  REQUIRE(vectorOne.Size() == 7);
  REQUIRE(vectorOne.Capacity() == 10);
  REQUIRE(vectorOne.FreeCapacity() == 3);

  Vector<int, 20> vectorTwo{1, 2, 3, 4, 5};
  REQUIRE(vectorTwo.Capacity() == 20);

  Vector<int, 100> vectorThree{1, 2, 3, 4, 5};
  REQUIRE(vectorThree.Capacity() == 100);
}
