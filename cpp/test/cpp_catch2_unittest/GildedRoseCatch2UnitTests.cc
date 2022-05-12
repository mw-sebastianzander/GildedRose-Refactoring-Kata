#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "Catch.hpp"
#include "GildedRose.h"

Item updateQuality(Item item)
{
    vector<Item> items;
    items.push_back(item);
    GildedRose app(items);
    app.updateQuality();
    return items[0];
}

TEST_CASE("Quality degrades")
{
    auto item = updateQuality(Item("Foo", 1, 10));
    REQUIRE(9 == item.quality);

}

TEST_CASE("Once the sell by date has passed, Quality degrades twice as fast")
{
    vector<Item> items;
    items.push_back(Item("Foo", 0, 10));
    GildedRose app(items);
    app.updateQuality();
    REQUIRE(8 == app.items[0].quality);
}

TEST_CASE("sellIn decreases")
{
    vector<Item> items;
    items.push_back(Item("Foo", 0, 0));
    GildedRose app(items);
    app.updateQuality();
    REQUIRE(-1 == app.items[0].sellIn);
}


/*
	- Once the sell by date has passed, Quality degrades twice as fast
	- The Quality of an item is never negative
	- "Aged Brie" actually increases in Quality the older it gets
	- The Quality of an item is never more than 50
	- "Sulfuras", being a legendary item, never has to be sold or decreases in Quality
	- "Backstage passes", like aged brie, increases in Quality as its SellIn value approaches;
	Quality increases by 2 when there are 10 days or less and by 3 when there are 5 days or less but
	Quality drops to 0 after the concert
*/
