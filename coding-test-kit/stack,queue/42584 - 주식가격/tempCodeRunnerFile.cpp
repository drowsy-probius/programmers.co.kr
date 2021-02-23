  test_case = solution({1, 2, 3, 2, 3});
  test_result = {4, 3, 1, 1, 0};
  assert(test_case == test_result);

  test_case = solution({1,2,3,4,5});
  test_result = {4,3,2,1,0};
  assert(test_case == test_result);