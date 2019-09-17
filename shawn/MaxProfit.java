public class MaxProfit {

	/*
	 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
	 * 
	 * 
	 * 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
	 * buy = max(buy, sell - price[i])
	 * sell = max(sell,   buy + prices[i] )
	 * 
	 * 边界
			第一天 buy = -prices[0], sell = 0，最后返回 sell 即可。
	 */
	public int maxProfit(int[] prices) {
        if(prices.length <= 1)
            return 0;
        int buy = -prices[0], sell = 0;
        for(int i = 1; i < prices.length; i++) {
            buy = Math.max(buy, -prices[i]);
            sell = Math.max(sell, prices[i] + buy);

        }
        return sell;
    }
	
	/*
	 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

		设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
	 * 
	 * 	输入: [7,1,5,3,6,4]
		输出: 7
		解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
		     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
	 * 
	 * 
	 * 		buy = max(buy, sell - price[i])

			sell = max(sell,   buy + prices[i] )
	 *
	 *	边界
		第一天 buy = -prices[0], sell = 0，最后返回 sell 即可。
	 *
	 *
	 */
	public int maxProfit2(int[] prices) {
        if(prices.length <= 1)
            return 0;
        int buy = -prices[0], sell = 0;
        for(int i = 1; i < prices.length; i++) {
        	sell = Math.max(sell, prices[i] + buy);
            buy = Math.max( buy,sell - prices[i]);

        }
        return sell;
    }
	
	/*
	 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

		设计一个算法来计算你所能获取的最大利润。你最多可以完成  *** 两笔 ***   交易。


	 * 
	 * 输入: [3,3,5,0,0,3,1,4]
		输出: 6
		解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
		     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
	 * 
	 * 状态
		有 第一次买入（fstBuy） 、 第一次卖出（fstSell）、第二次买入（secBuy） 和 第二次卖出（secSell） 这四种状态。
	 * 
	 * 转移方程
	 * fstBuy = max(fstBuy ，  -price[i])

		fstSell = max(fstSell，fstBuy + prices[i] )
		
		secBuy = max(secBuy ，fstSell -price[i]) (受第一次卖出状态的影响)
		
		secSell = max(secSell ，secBuy + prices[i] )
	 * 
	 * 边界
			一开始 fstBuy = -prices[0]
			
			买入后直接卖出，fstSell = 0
			
			买入后再卖出再买入，secBuy - prices[0]
			
			买入后再卖出再买入再卖出，secSell = 0
			
			最后返回 secSell 。
	 * 
	 */
	public int maxProfit3(int[] prices) {
        int fstBuy = Integer.MIN_VALUE, fstSell = 0;
        int secBuy = Integer.MIN_VALUE, secSell = 0;
        for(int i = 0; i < prices.length; i++) {
            fstBuy = Math.max(fstBuy, -prices[i]);
            fstSell = Math.max(fstSell, fstBuy + prices[i]);
            secBuy = Math.max(secBuy, fstSell -  prices[i]);
            secSell = Math.max(secSell, secBuy +  prices[i]); 
        }
        return secSell;

    }
	
}
