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

// TEST_CASE(
//     "Returns a pointer to the last occurrence of the element with
//     matching " "data.",
//     "[Find Last]") {
//   SECTION(
//       "Returns nullptr if no element in the Vector matches the passed in
//       " "data.") {
//     Vector<int,10> vector{1, 2, 3, 4, 5};

//     REQUIRE(vector.FindLast(12) == nullptr);
//   }

//   SECTION("Returns a pointer to the last element found with matching
//   data.")
//   {
//     Vector<int,10> vector{1, 2, 3, 4, 5, 1, 2, 3};

//     REQUIRE(vector[0] == 1);
//     REQUIRE(vector[1] == 2);
//     REQUIRE(vector[2] == 3);
//     REQUIRE(vector[3] == 4);
//     REQUIRE(vector[4] == 5);
//     REQUIRE(vector[5] == 1);
//     REQUIRE(vector[6] == 2);
//     REQUIRE(vector[7] == 3);

//     REQUIRE(*(vector.FindLast(1)) == 1);
//     REQUIRE(*(vector.FindLast(2)) == 2);
//     REQUIRE(*(vector.FindLast(3)) == 3);

//     *(vector.FindLast(1)) += 10;
//     *(vector.FindLast(2)) += 10;
//     *(vector.FindLast(3)) += 10;

//     REQUIRE(vector[0] == 1);
//     REQUIRE(vector[1] == 2);
//     REQUIRE(vector[2] == 3);
//     REQUIRE(vector[3] == 4);
//     REQUIRE(vector[4] == 5);
//     REQUIRE(vector[5] == 11);
//     REQUIRE(vector[6] == 12);
//     REQUIRE(vector[7] == 13);
//   }

//   SECTION(
//       "Returns a pointer to the last element in which the provided
//       function " "returned a truthy value for its value.") {
//     Vector<int,10> vector{1, 2, 3, 4, 5};

//     int* foundElement = vector.FindLast([](const int& number, int) {
//       if (number > 2) {
//         return true;
//       }

//       return false;
//     });

//     REQUIRE(*foundElement == 5);

//     int* foundElementTwo = vector.FindLast([](const int& number, int) {
//       if (number % 2 == 0) {
//         return true;
//       }

//       return false;
//     });

//     REQUIRE(*foundElementTwo == 4);
//   }
// }

// TEST_CASE("Sorts the Vector using Merge Sort.", "[Sort]") {
//   Vector<int,10> vector{5, 4, 3, 2, 1};

//   REQUIRE(vector[0] == 5);
//   REQUIRE(vector[1] == 4);
//   REQUIRE(vector[2] == 3);
//   REQUIRE(vector[3] == 2);
//   REQUIRE(vector[4] == 1);

//   vector.Sort();

//   REQUIRE(vector[0] == 1);
//   REQUIRE(vector[1] == 2);
//   REQUIRE(vector[2] == 3);
//   REQUIRE(vector[3] == 4);
//   REQUIRE(vector[4] == 5);
// }

// TEST_CASE("Reverses the Vector.", "[Reverse]") {
//   Vector<int,10> vector{1, 4, 3, 5, 2};

//   REQUIRE(vector[0] == 1);
//   REQUIRE(vector[1] == 4);
//   REQUIRE(vector[2] == 3);
//   REQUIRE(vector[3] == 5);
//   REQUIRE(vector[4] == 2);

//   vector.Reverse();

//   REQUIRE(vector[0] == 2);
//   REQUIRE(vector[1] == 5);
//   REQUIRE(vector[2] == 3);
//   REQUIRE(vector[3] == 4);
//   REQUIRE(vector[4] == 1);
// }

// TEST_CASE(
//     "Removes the proved index from the Vector, and returns true;
//     otherwise " "returns false.",
//     "[Remove Index If]") {
//   SECTION("Returns false when the list is empty.") {
//     Vector<int,10> vector;

//     bool removed = vector.RemoveIndexIf(2, [](const int& number) {
//       if (number > 2) {
//         return true;
//       }

//       return false;
//     });

//     REQUIRE(removed == false);
//   }

//   SECTION(
//       "Returns false when no element in the Vector suffices the provided
//       " "function. No element is removed from the Vector.") {
//     Vector<int,10> vector{1, 2, 3, 4, 5};

//     bool removed = vector.RemoveIndexIf(0, [](const int& number) {
//       if (number == 10) {
//         return true;
//       }
//       return false;
//     });

//     REQUIRE(removed == false);
//   }

//   SECTION(
//       "Returns true and removes the element at the provided index in the
//       " "Vector.") {
//     Vector<int,10> vector{1, 2, 3, 4, 5};

//     bool removed = vector.RemoveIndexIf(0, [](const int& number) {
//       if (number < 5) {
//         return true;
//       }

//       return false;
//     });

//     REQUIRE(removed == true);
//   }
// }

// TEST_CASE(
//     "Applies a transformation to every element in the Vector, based on
//     the " "passed in Function.",
//     "[For Each]") {
//   Vector<int,10> vector{1, 2, 3, 4, 5};

//   REQUIRE(vector[0] == 1);
//   REQUIRE(vector[1] == 2);
//   REQUIRE(vector[2] == 3);
//   REQUIRE(vector[3] == 4);
//   REQUIRE(vector[4] == 5);

//   vector.ForEach([](const int& number, int) { return number + 10; });

//   REQUIRE(vector[0] == 11);
//   REQUIRE(vector[1] == 12);
//   REQUIRE(vector[2] == 13);
//   REQUIRE(vector[3] == 14);
//   REQUIRE(vector[4] == 15);
// }

// TEST_CASE(
//     "Returns true if any of the elements in the Vector, suffice the
//     passed in " "Function.",
//     "[Any]") {
//   SECTION(
//       "Returns false if no elements in the Vector Suffice the passed in "
//       "Function.") {
//     Vector<int,10> vector{1, 2, 3, 4, 5};

//     bool any = vector.Any([](const int& number, int) {
//       if (number > 100) {
//         return true;
//       }

//       return false;
//     });

//     REQUIRE(any == false);
//   }

//   SECTION(
//       "Returns true if any elements in the Vector Suffice the passed in "
//       "Function.") {
//     Vector<int,10> vector{1, 2, 3, 4, 5};

//     bool any = vector.Any([](const int& number, int) {
//       if (number > 4) {
//         return true;
//       }

//       return false;
//     });

//     REQUIRE(any == true);
//   }
// }

// TEST_CASE(
//     "Returns true if all of the elements in the Vector, suffice the
//     passed in " "Function.",
//     "[Any]") {
//   SECTION(
//       "Returns false if no elements in the Vector Suffice the passed in "
//       "Function.") {
//     Vector<int,10> vector{1, 2, 3, 4, 5};

//     bool every = vector.Every([](const int& number, int) {
//       if (number > 100) {
//         return true;
//       }

//       return false;
//     });

//     REQUIRE(every == false);
//   }

//   SECTION(
//       "Returns false if even one element does not suffice the passed in "
//       "function.") {
//     Vector<int,10> vector{1, 2, 3, 4, 5};

//     bool every = vector.Every([](const int& number, int) {
//       if (number > 1) {
//         return true;
//       }

//       return false;
//     });

//     REQUIRE(every == false);
//   }

//   SECTION(
//       "Returns true if all elements in the Vector suffice the passed in "
//       "function.") {
//     Vector<int,10> vector{1, 2, 3, 4, 5};

//     bool every = vector.Every([](const int& number, int) {
//       if (number < 10) {
//         return true;
//       }

//       return false;
//     });

//     REQUIRE(every == true);
//   }
// }

// TEST_CASE("Shuffles the elements of the Vector.", "[Shuffle]") {
//   Vector<int,10> vectorOne{1, 2, 3, 4, 5};
//   Vector<int,10> vectorTwo{1, 2, 3, 4, 5};

//   REQUIRE(vectorOne == vectorTwo);

//   vectorOne.Shuffle();

//   REQUIRE(vectorOne != vectorTwo);
// }

// TEST_CASE(
//     "Swaps the data of two memebers of type T. Takes in two T pointers to
//     swap " "the elements in place.",
//     "[Swap Elements]") {
//   Vector<int,10> vector{1, 2, 3, 4, 5};

//   REQUIRE(vector[0] == 1);
//   REQUIRE(vector[1] == 2);
//   REQUIRE(vector[2] == 3);
//   REQUIRE(vector[3] == 4);
//   REQUIRE(vector[4] == 5);

//   vector.Swap(&vector[0], &vector[4]);

//   REQUIRE(vector[0] == 5);
//   REQUIRE(vector[1] == 2);
//   REQUIRE(vector[2] == 3);
//   REQUIRE(vector[3] == 4);
//   REQUIRE(vector[4] == 1);
// }

// TEST_CASE("Swaps the elements of two Vectors.", "[Swap Vectors]") {
//   SECTION("Swaps the Vectors when the first vector has more elements.") {
//     Vector<int,10> vectorOne{1, 2, 3, 4, 5};
//     Vector<int,10> vectorTwo{1, 2};

//     REQUIRE(vectorOne[0] == 1);
//     REQUIRE(vectorOne[1] == 2);
//     REQUIRE(vectorOne[2] == 3);
//     REQUIRE(vectorOne[3] == 4);
//     REQUIRE(vectorOne[4] == 5);

//     REQUIRE(vectorTwo[0] == 1);
//     REQUIRE(vectorTwo[1] == 2);

//     REQUIRE(vectorOne.Size() == 5);
//     REQUIRE(vectorTwo.Size() == 2);

//     vectorOne.Swap(vectorTwo);

//     REQUIRE(vectorTwo[0] == 1);
//     REQUIRE(vectorTwo[1] == 2);
//     REQUIRE(vectorTwo[2] == 3);
//     REQUIRE(vectorTwo[3] == 4);
//     REQUIRE(vectorTwo[4] == 5);

//     REQUIRE(vectorOne[0] == 1);
//     REQUIRE(vectorOne[1] == 2);

//     REQUIRE(vectorOne.Size() == 2);
//     REQUIRE(vectorTwo.Size() == 5);
//   }

//   SECTION("Swaps the vectors when both the vectors have the same
//   length.") {
//     Vector<int,10> vectorOne{1, 2, 3};
//     Vector<int,10> vectorTwo{6, 7, 8};

//     REQUIRE(vectorOne[0] == 1);
//     REQUIRE(vectorOne[1] == 2);
//     REQUIRE(vectorOne[2] == 3);

//     REQUIRE(vectorTwo[0] == 6);
//     REQUIRE(vectorTwo[1] == 7);
//     REQUIRE(vectorTwo[2] == 8);

//     REQUIRE(vectorOne.Size() == 3);
//     REQUIRE(vectorTwo.Size() == 3);

//     vectorOne.Swap(vectorTwo);

//     REQUIRE(vectorTwo[0] == 1);
//     REQUIRE(vectorTwo[1] == 2);
//     REQUIRE(vectorTwo[2] == 3);

//     REQUIRE(vectorOne[0] == 6);
//     REQUIRE(vectorOne[1] == 7);
//     REQUIRE(vectorOne[2] == 8);

//     REQUIRE(vectorOne.Size() == 3);
//     REQUIRE(vectorTwo.Size() == 3);
//   }
// }

// TEST_CASE("Concatenates one vector to the end of another.", "[Concat]") {
//   Vector<int,10> vectorOne{1, 2, 3, 4, 5};
//   Vector<int,10> vectorTwo{6, 7, 8, 9, 10};

//   REQUIRE(vectorOne[0] == 1);
//   REQUIRE(vectorOne[1] == 2);
//   REQUIRE(vectorOne[2] == 3);
//   REQUIRE(vectorOne[3] == 4);
//   REQUIRE(vectorOne[4] == 5);

//   REQUIRE(vectorTwo[0] == 6);
//   REQUIRE(vectorTwo[1] == 7);
//   REQUIRE(vectorTwo[2] == 8);
//   REQUIRE(vectorTwo[3] == 9);
//   REQUIRE(vectorTwo[4] == 10);

//   vectorOne.Concat(vectorTwo);

//   REQUIRE(vectorOne[0] == 1);
//   REQUIRE(vectorOne[1] == 2);
//   REQUIRE(vectorOne[2] == 3);
//   REQUIRE(vectorOne[3] == 4);
//   REQUIRE(vectorOne[4] == 5);
//   REQUIRE(vectorOne[5] == 6);
//   REQUIRE(vectorOne[6] == 7);
//   REQUIRE(vectorOne[7] == 8);
//   REQUIRE(vectorOne[8] == 9);
//   REQUIRE(vectorOne[9] == 10);
// }

// TEST_CASE("Returns the amount of free capacity the vector has
// available.",
//           "[Free Capacity]") {
//   Vector<int,10> vector{1, 2, 3, 4, 5};

//   REQUIRE(vector.Size() == 5);
//   REQUIRE(vector.Capacity() == 5);
//   REQUIRE(vector.FreeCapacity() == 0);

//   vector.PushBack(6);

//   REQUIRE(vector.Size() == 6);
//   REQUIRE(vector.Capacity() == 10);
//   REQUIRE(vector.FreeCapacity() == 4);

//   vector.Reserve(20);

//   REQUIRE(vector.Size() == 6);
//   REQUIRE(vector.Capacity() == 20);
//   REQUIRE(vector.FreeCapacity() == 14);
// }

// TEST_CASE(
//     "Removes elements in the Vector which suffice the passed in Function.
//     " "Returns the amount of elements which were removed.",
//     "[Remove If]") {
//   SECTION("Returns 0 if the list is empty.") {
//     Vector<int,10> vector{1, 2, 3, 4, 5};

//     REQUIRE(vector.Size() == 5);

//     int amountRemoved = vector.RemoveIf([](const int& number) {
//       if (number > 10) {
//         return true;
//       }

//       return false;
//     });

//     REQUIRE(amountRemoved == 0);
//     REQUIRE(vector.Size() == 5);
//   }

//   SECTION(
//       "Returns the amount of elements removed, and removes the elements
//       which " "suffice the passed in function.") {
//     Vector<int,10> vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//     REQUIRE(vector.Size() == 10);
//     REQUIRE(vector.Capacity() == 10);
//     REQUIRE(vector.FreeCapacity() == 0);

//     int amountRemoved = vector.RemoveIf([](const int& number) {
//       if (number % 2 == 0) {
//         return true;
//       }

//       return false;
//     });

//     REQUIRE(vector.Size() == 5);
//     REQUIRE(vector.Capacity() == 10);
//     REQUIRE(vector.FreeCapacity() == 5);

//     REQUIRE(amountRemoved == 5);

//     REQUIRE(vector[0] == 1);
//     REQUIRE(vector[1] == 3);
//     REQUIRE(vector[2] == 5);
//     REQUIRE(vector[3] == 7);
//     REQUIRE(vector[4] == 9);
//   }
// }

// TEST_CASE(
//     "Returns the index of the element with matching data, otherwise
//     returns "
//     "-1.",
//     "[Binary Search]") {
//   SECTION(
//       "Returns -1 if no element in the Vector matches the passed in
//       data.") {
//     Vector<int,10> vector{1, 2, 3, 4, 5};

//     int index = vector.BinarySeach(12);

//     REQUIRE(index == -1);
//   }

//   SECTION(
//       "Returns the index of the element whose data matches the passed in
//       " "data.") {
//     Vector<int,10> vector{1, 2, 3, 4, 5};

//     int index = vector.BinarySeach(1);

//     REQUIRE(index == 0);

//     index = vector.BinarySeach(5);

//     REQUIRE(index == 4);

//     index = vector.BinarySeach(3);

//     REQUIRE(index == 2);
//   }
// }