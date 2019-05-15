/*global describe,it*/

var assert = require("assert");
var lib = require("../");
var Semaphore = lib.Semaphore;

describe("Semaphore", function() {
  it("constructor should throw with bad arguments", function() {
    assert.throws(function() {
      new Semaphore();
    });
  });

  it("should release", function() {
    var semaphore = new Semaphore("demo-semaphore");
    assert(semaphore.release());
  });

  it("should release twice successfully", function() {
    var semaphore = new Semaphore("demo-semaphore");
    assert(semaphore.release());
    assert(!semaphore.release());
  });

  describe("isActive", function() {
    it("should work", function() {
      var semaphore = new Semaphore("demo-semaphore");
      assert(semaphore.isActive());
      semaphore.release();
      assert(!semaphore.isActive());
    });
  });
});

describe("isActive", function() {
  it("should throw on bad argument", function() {
    assert.throws(function() {
      lib.isActive();
    });
  });

  it("should work", function() {
    assert(!lib.isActive("demo-semaphore"));

    var semaphore = new Semaphore("demo-semaphore");
    assert(semaphore.isActive());
    assert(lib.isActive("demo-semaphore"));

    semaphore.release();
    assert(!semaphore.isActive());
    assert(!lib.isActive("demo-semaphore"));
  });
});
